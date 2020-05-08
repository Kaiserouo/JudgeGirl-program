#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct rectangle {
    int height;
    int width;
} Rectangle;

int numRect;
Rectangle rect[201];
int maxRect, maxSum;

// if a can be under b, return 1 else 0
int stackable(Rectangle a, Rectangle b){
    return ((a.height>=b.height && a.width>=b.width) || (a.height>=b.width && a.width>=b.height)) ? 1 : 0;
}

// return 0 and change global instead
int build(int index, int numBuilt, int *state){
    // terminal
    if(index == numRect){
        if(numBuilt >= maxRect){
            // calculate sum
            int sum = 0;
            for(int i = 0; i < numBuilt; i++){
                sum += state[i];
            }
            if(numBuilt > maxRect)   maxRect = numBuilt, maxSum = sum;
            if(numBuilt == maxRect && sum > maxSum)  maxSum = sum;   
        }
        return 0;
    }

    // haven't built
    if(numBuilt == 0){
        build(index+1, numBuilt, state);
        state[numBuilt] = index;
        build(index+1, numBuilt+1, state);
    }
    // any other case
    else{
        int canStack = stackable(rect[ state[numBuilt-1] ], rect[ index ]);
        if(canStack){
            build(index+1, numBuilt, state);
            state[numBuilt] = index;
            build(index+1, numBuilt+1, state);
        }else{
            build(index+1, numBuilt, state);
        }
    }
}

int main(){
    scanf("%d", &numRect);
    for(int i = 0; i < numRect; i++){
        scanf("%d%d", &rect[i].height, &rect[i].width);
    }
    maxRect = 0, maxSum = 0;
    int state[200] = {0};
    build(0, 0, state);
    printf("%d %d\n", maxRect, maxSum);
}