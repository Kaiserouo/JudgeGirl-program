#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int main(){
    int ready_A = 0, ready_B = 0;
    int time_arrive, time_A, time_B;
    while(scanf("%d%d%d", &time_arrive, &time_A, &time_B) != EOF){
        // A
        if(time_arrive < ready_A){
            ready_A += time_A;
        }
        else{
            ready_A = time_arrive + time_A;
        }
        // B
        if(ready_B < ready_A){
            ready_B = ready_A + time_B;
        }
        else{
            ready_B += time_B;
        }

        printf("%d\n", ready_B);
    }
}