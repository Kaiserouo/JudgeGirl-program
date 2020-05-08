#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 500
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Abs(x) ((x) > 0 ? (x) : -(x))

typedef struct{
    int r;
    int c;
} Vector2D;

// close on left and open on right: [...) !
bool BetweenRange(int range_low, int range_high, int target){
    return target >= range_low && target < range_high;
}

int CountObstacle(char map[MAXN][MAXN], Vector2D pos, Vector2D size){
    int count = 0;
    for(int ri = pos.r; ri < pos.r + size.r; ri++){
        for(int ci = pos.c; ci < pos.c + size.c; ci++){
            if(map[ri][ci] == 2)
                count++;
        }
    }
    return count;
}

void ClearObstacle(char map[MAXN][MAXN], Vector2D pos, Vector2D size){
    for(int ri = pos.r; ri < pos.r + size.r; ri++){
        for(int ci = pos.c; ci < pos.c + size.c; ci++){
            map[ri][ci] = 0;
        }
    }
}

// defines region I, A, B, C:
// 111100       000000      000000  I is intersection, don't count obstacle
// 111100  ->   001111  =>  00IIBB, A at up/down
// 111100       001111      00IIBB  B at left/right
// 000000       001111      00AACC  C at corner
void MoveTank(char map[MAXN][MAXN], Vector2D dir, 
              Vector2D *map_size, Vector2D *tank_pos, Vector2D *tank_size){
    Vector2D moved_tank_pos = {tank_pos->r + dir.r, tank_pos->c + dir.c};
    // ensure not out of range
    if(!(BetweenRange(0, map_size->r, moved_tank_pos.r) &&
         BetweenRange(0, map_size->c, moved_tank_pos.c) &&
         BetweenRange(0, map_size->r, moved_tank_pos.r + tank_size->r - 1) &&
         BetweenRange(0, map_size->c, moved_tank_pos.c + tank_size->c - 1))){
        return;
    }

    // calculate new area's pos & size
    Vector2D A_pos = {dir.r > 0 ? tank_pos->r + tank_size->r : moved_tank_pos.r,
                      dir.c > 0 ? moved_tank_pos.c : tank_pos->c},
             B_pos = {dir.r > 0 ? moved_tank_pos.r : tank_pos->r,
                      dir.c > 0 ? tank_pos->c + tank_size->c : moved_tank_pos.c},
             C_pos = {dir.r > 0 ? tank_pos->r + tank_size->r : moved_tank_pos.r,
                      dir.c > 0 ? tank_pos->c + tank_size->c : moved_tank_pos.c},
             A_size = {Abs(dir.r), tank_size->c - Abs(dir.c)},
             B_size = {tank_size->r - Abs(dir.r), Abs(dir.c)},
             C_size = {Abs(dir.r), Abs(dir.c)};

    if(CountObstacle(map, A_pos, A_size) +
       CountObstacle(map, B_pos, B_size) +
       CountObstacle(map, C_pos, C_size) <= 1){
           ClearObstacle(map, A_pos, A_size), ClearObstacle(map, B_pos, B_size), ClearObstacle(map, C_pos, C_size);
           *tank_pos = (Vector2D){moved_tank_pos.r, moved_tank_pos.c};
    }
    else{
        return;
    }
}
void PrintMap(char map[MAXN][MAXN], 
              Vector2D *map_size, Vector2D *tank_pos, Vector2D *tank_size){
    for(int ri = 0; ri < map_size->r; ri++){
        for(int ci = 0; ci < map_size->c; ci++){
            if(BetweenRange(tank_pos->r, tank_pos->r + tank_size->r, ri) &&
               BetweenRange(tank_pos->c, tank_pos->c + tank_size->c, ci)){
                   printf("1");
            }
            else{
                printf("%d", map[ri][ci]);
            }
        }
        printf("\n");
    }

    // printf("[*] tank_pos = {%d, %d}\n    tank_size = {%d, %d}\n", tank_pos->r, tank_pos->c, tank_size->r, tank_size->c);
}

// use array to store obstacle, won't update tank pos (1) in an attempt to reduce time.
int main(){
    char map[MAXN][MAXN];   // note the order: (r, c) = (y, x)
                            // will use (r, c) throughout this program
    Vector2D map_size;
    Vector2D tank_size;
    Vector2D tank_pos = {0, 0};

    // input
    memset(map, 0, MAXN*MAXN * sizeof(char));
    scanf("%d%d%d%d", &map_size.r, &map_size.c, &tank_size.r, &tank_size.c);
    int num_obst;
    scanf("%d", &num_obst);
    for(int iter = 0; iter < num_obst; iter++){
        int r, c;
        scanf("%d%d", &c, &r);
        map[r][c] = 2;
    }

    // instruction execution
    int instr;
    Vector2D dir[5] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}};
    while(scanf("%d", &instr) != EOF){
        switch(instr){
        case 0: // print
            PrintMap(map, &map_size, &tank_pos, &tank_size);
            break;
        case 1: // right
        case 2: // down
        case 3: // left
        case 4: // up
        case 5: // bottom-right
            MoveTank(map, dir[instr-1], &map_size, &tank_pos, &tank_size);
            break;
        }
    }
}
