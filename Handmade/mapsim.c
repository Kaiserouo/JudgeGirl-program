#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include "map.h"


int main(){
    Point loc = {3, 3};
    Map map;
    initialize_map(&map, 10, 20);
    Point obs = {5, 5};
    put_on_map(&map, MAP_OBSTACLE, loc);
    print_map(&loc, &map);
    char in;
    while(1){
        in = getch();
        if(in == 'c')exit(0);
        system("cls");
        move_player(&loc, input_to_delta(in), &map);
        print_map(&loc, &map);
    }
    
}

