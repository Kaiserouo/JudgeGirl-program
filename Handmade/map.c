#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <math.h>
/* details for definition */
/*
** map: right +x, down +y
** 
*/

/* define symbol for map */

#define MAP_PLAYER '*'
#define MAP_AIR '.'
#define MAP_OBSTACLE 'O'
#define MAP_INVISIBLE ' '

#define CONTROL_UP 'w'
#define CONTROL_DOWN 's'
#define CONTROL_LEFT 'a'
#define CONTROL_RIGHT 'd'

/* define function to make life somewhat easier */

#define loc(a,b,m) (a*(m->size.c) + b)    // (a,b) for (x,y), m for Map structure pointer
#define map_get_c(map,p) (((map)->m)[loc((p)->r, (p)->c, map)]) 

/* structure */
typedef struct{
    int r;
    int c;
} Point;
typedef struct{
    char *m;  // for storing whole map
    Point size; // for map size
} Map;


/* function */

// return delta(pos) from char input
Point input_to_delta(char c){
    if(c == CONTROL_LEFT)   return (Point){0, -1};
    if(c == CONTROL_RIGHT)   return (Point){0, 1};
    if(c == CONTROL_UP)   return (Point){-1, 0};
    if(c == CONTROL_DOWN)   return (Point){1, 0};
    else  return (Point){0, 0};
}

// print map
void print_map(Point *player_loc, Map *map){
    for(int i = 0; i < map->size.r; i++){
        for(int j = 0; j < map->size.c; j++){
            /* player */
            if(i == player_loc->r && j == player_loc->c)  putchar(MAP_PLAYER);
            else putchar( (map->m)[loc(player_loc->r, player_loc->c, map)] );
        }
        putchar('\n');
    }
}

// add player pos and delta(pos), and determine whether to move or not
void move_player(Point *loc, Point delta, Map *map){
    loc->r += delta.r, loc->c += delta.c;

    // out of range
    if(loc->r < 0)  loc->r = 0;
    if(loc->c < 0)  loc->c = 0;
    if(loc->r >= map->size.r)  loc->r = map->size.r - 1;
    if(loc->c >= map->size.c)  loc->c = map->size.c - 1;

    return;
}

// initialize map given Map pointer and initial r/c
void initialize_map(Map *map, int r, int c){
    map->size = (Point){r,c};
    map->m = malloc(r*c);
    memset(map->m, MAP_AIR, r*c);
}

// put c on map with location loc
void put_on_map(Map *map, char c, Point location){
    map_get_c(map, &location) = c;
}