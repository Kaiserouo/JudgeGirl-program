#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

bool valid(int max_x, int max_y, int x, int y){
    return (x >= 0 && y >= 0 && x < max_x && y < max_y);
}

int main(){
    int instr;  // instruction
    int max_x, max_y;   // assume cartesion coordinate
    int x = 0, y = 0;   // robot position;

    scanf("%d%d", &max_x, &max_y);
    printf("0\n0\n");   // initial position
    while(scanf("%d", &instr) != EOF){
        int new_x = -1, new_y = -1;
        switch(instr % 5){
        case 1:
            new_x = x + instr;
            new_y = y;
            break;
        case 2:
            new_x = x - instr;
            new_y = y;
            break;
        case 3:
            new_y = y + instr;
            new_x = x;
            break;
        case 4:
            new_y = y - instr;
            new_x = x;
            break;
        default:
            break;
        }
        if(valid(max_x, max_y, new_x, new_y)){
            x = new_x; y = new_y;
            printf("%d\n%d\n", new_x, new_y);
        }
    }

}