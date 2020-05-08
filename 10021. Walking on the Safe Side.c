#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int walk(int map_r, int map_c, char map[100][100]){
    int count[map_r][map_c];
    for(int i = 0; i < map_r; i++){
        for(int j = 0; j < map_c; j++){
            if(map[i][j]){
                count[i][j] = 0;
            }
            else if(i == 0 && j == 0){
                count[i][j] = 1;
            }
            else if(i == 0){
                count[i][j] = count[i][j-1];
            }
            else if(j == 0){
                count[i][j] = count[i-1][j];
            }
            else{
                count[i][j] = (count[i-1][j] + count[i][j-1]) % 10000;
            }
        }
    }
    return count[map_r-1][map_c-1];
}

int main(){
    int r, c;
    char map[100][100];
    while(scanf("%d%d", &r, &c) != EOF){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                scanf("%d", &map[i][j]);
            }
        }
        printf("%d\n", walk(r, c, map));
    }
}