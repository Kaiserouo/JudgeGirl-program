#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define dist_z(ptr) ((ptr)->x * (ptr)->x + (ptr)->y * (ptr)->y)
#define dist(a, b) (((a).x - (b).x)*((a).x - (b).x) + ((a).y - (b).y)*((a).y - (b).y))
typedef struct pos{
    int x;
    int y;
} Pos;

int compare(const void *a, const void *b){
    Pos *ptr1 = (Pos *)a;
    Pos *ptr2 = (Pos *)b;

    if(dist_z(ptr1) < dist_z(ptr2)) return -1;
    else if(dist_z(ptr1) > dist_z(ptr2)) return 1;
    else if(ptr1->x < ptr2->x) return -1;
    else if(ptr1->x > ptr2->x) return 1;
    else if(ptr1->y < ptr2->y) return -1;
    else if(ptr1->y > ptr2->y) return 1;
    else return 0;
}

int walk(Pos city[], int num){
    int sum = 0;
    sum += dist_z(city);
    for(int i = 0; i < num-1; i++){
        sum += dist(city[i], city[i+1]);
    }
    return sum;
}

int main(){
    Pos city[100001];
    int num = 0;
    while(scanf("%d %d", &city[num].x, &city[num].y) != EOF){
        num++;
    }
    qsort(city, num, sizeof(Pos), compare);
    printf("%d\n", walk(city, num));
}