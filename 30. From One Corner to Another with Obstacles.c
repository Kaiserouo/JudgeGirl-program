#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int r, c;
char array[12][12];
typedef struct{
    int x;
    int y;
} Point;
int walk(Point p){
    if(p.x<0 || p.y>=c)    return 0;
    if(!array[p.x][p.y])    return 0;
    if(p.x==0 && p.y==c-1)    return 1;
    return walk((Point){p.x-1, p.y})+walk((Point){p.x, p.y+1});
}

int main(){
    scanf("%d%d", &r, &c);
    Point p = {r-1, 0};
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &array[i][j]);
        }
    }
    printf("%d", walk(p));
}