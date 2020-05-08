#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

void put_ball(int *bucket, int ball){
    *bucket -= ball;
    return;
}

int main(){
    int size_A, size_B;
    int size_ball;
    int mode;

    scanf("%d%d%d", &size_A, &size_B, &mode);
    while(scanf("%d", &size_ball) != EOF){
        if(mode == 0){  // first fit
            if(size_ball <= size_A){
                put_ball(&size_A, size_ball);
            }
            else if(size_ball <= size_B){
                put_ball(&size_B, size_ball);
            }
        }

        else if(mode == 1){ // best fit
            if(size_ball <= size_A && size_ball <= size_B){
                if(size_A > size_B){
                    put_ball(&size_B, size_ball);
                }
                else if(size_A <= size_B){
                    put_ball(&size_A, size_ball);
                }
            }
            else if(size_ball <= size_A){
                put_ball(&size_A, size_ball);
            }
            else if(size_ball <= size_B){
                put_ball(&size_B, size_ball);
            }
        }

        printf("%d %d\n", size_A, size_B);
    }
}