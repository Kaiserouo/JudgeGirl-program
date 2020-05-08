#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int main(){
    int num_element;
    
    while(scanf("%d", &num_element) != EOF){
        int max, min;
        int cur;
        int iter;
        for(iter = 0; iter < num_element; iter++){
            if(scanf("%d", &cur) == EOF){
                printf("%d\n", min);
                break;
            }
            else{
                if(iter == 0){  // first time: initialize
                    max = min = cur;
                }
                else{
                    max = cur > max ? cur : max;
                    min = cur < min ? cur : min;
                }
            }
        }
        if(iter == num_element){
            printf("%d\n", max);
        }
        else{
            break;
        }
    }
}