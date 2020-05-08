#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define X 9
#define Y 9
#define outOfRange(x, y) (x<0 || y<0 || x>=X || y>=Y)
char sumField[X][Y];
char field[X][Y] = {0};
int checkBit(int r, int c, int op){
    // printf("    cBit(%d, %d, %d),", r, c, op);
    int ret = 0;
    int s = 0;
    if(outOfRange(r,c)){
        // printf("return %d\n", 1);
        return 1;
    }

    for(int j = r-1; j <= r+1 && ret == 0; j++){
        for(int k = c-1; k <= c+1; k++){
            if(!outOfRange(j,k))    s += field[j][k];
        }
    }
    if(op == -2 && s == sumField[r][c])ret = 1;
    else if(op != -2 && s <= sumField[r][c])ret = 1;
    
    // printf("return %d\n", ret);
    return ret;
}
int check(int i){
    // printf("c %d\n", i);
    int r = i/Y;
    int c = i%Y;
    for(int j = r-1; j <= r+1; j++){
        for(int k = c-1; k <= c+1; k++){
            if(!checkBit(j, k, j-r+k-c))return 0;
        }
    }
    return 1;
}
int checkAll(){
    // printf("cAll\n");
    for(int j = 0; j < X; j++){
        for(int k = 0; k < Y; k++){
            if(!checkBit(j, k, -2))return 0;
        }
    }
    return 1;
}
int simulation(int i){
    // printf("simu %d\n", i);
    if(i==X*Y+1){
        return checkAll();
    }

    // now at [i/Y][i%Y]
    
    // printf("put 1 at %d\n", i);
    field[i/Y][i%Y] = 1;
    if(check(i)) if(simulation(i+1)) return 1;
    // printf("put 0 at %d\n", i);
    field[i/Y][i%Y] = 0;
    if(check(i)) if(simulation(i+1)) return 1;
    return 0;
}


int main(){
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            scanf("%d", &sumField[i][j]);
        }
    }
    if(!simulation(0)){
        printf("no solution\n");
        return 0;
    }
    
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            printf("%d%s", field[i][j], j==Y-1?"\n":" ");
        }
    }
}