#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int r, c;
typedef struct{
    int x;
    int y;
} Point;
int walk(Point p){
    if(p.x>=r || p.y>=c)    return 0;
    if(p.x==r-1 && p.y==c-1)    return 1;
    return walk((Point){p.x+1, p.y})+walk((Point){p.x, p.y+1});
}
 
int main(){
    scanf("%d%d", &r, &c);
    Point p = {0,0};
    printf("%d", walk(p));
}