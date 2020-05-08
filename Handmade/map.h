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
#define map_get_c(map,p) ((map->m)[loc(p->r, p->c, map)]) 

/* structure */
typedef struct{
    int r;
    int c;
} Point;
typedef struct{
    char *m;  // for storing whole map
    Point size; // for map size
} Map;

/* function header */

// return delta(pos) from char input
Point input_to_delta(char c);

// print map
void print_map(Point *player_loc, Map *map);

// add player pos and delta(pos), and determine whether to move or not
void move_player(Point *loc, Point delta, Map *map);

// initialize map given Map pointer and initial r/c
void initialize_map(Map *map, int r, int c);

// put c on map with location loc
void put_on_map(Map *map, char c, Point location);