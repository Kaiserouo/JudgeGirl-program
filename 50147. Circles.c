#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int compare(const void *a, const void *b){
    if(*(int *)a < *(int *)b)   return -1;
    else if(*(int *)a > *(int *)b)   return 1;
    else if(*(int *)a == *(int *)b)   return 0;
}

int main(){
    int num;
    scanf("%d", &num);

    int point[num];
    for(int i = 0; i < num; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        point[i] = a*a + b*b;
    }

    qsort(point, num, sizeof(int), compare);
    

    int cur_num = 0;
    int cur_radius = 0;
    int max_num = 0;
    int max_radius = 0;
    for(int i = 0; i < num; i++){
        if(cur_radius == 0){
            cur_num = 1;
            cur_radius = point[i];
        }else{
            if(cur_radius == point[i]){
                cur_num++;
            }else{
                if(cur_num >= max_num)  max_num = cur_num, max_radius = cur_radius;
                cur_num = 1;
                cur_radius = point[i];
            }
        }
    }
    if(cur_num >= max_num)  max_num = cur_num, max_radius = cur_radius;
    printf("%d\n", max_radius);
}