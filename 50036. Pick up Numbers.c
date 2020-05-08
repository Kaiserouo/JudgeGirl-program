#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int numLeastPick, numNum, maximum;
int *numArray;
int *pickedNumber;

int sum(int numPicked){
    int s = 0;
    for(int i = 0; i < numPicked; i++){
        s += pickedNumber[i];
    }
    return s;
}

int simulation(int curIndex, int numPicked){
    if(curIndex == numNum){   // terminal
        if(numPicked < numLeastPick)    return 0;
        else if (sum(numPicked) <= maximum) return 1;
        else return 0;
    }
    else{
        pickedNumber[numPicked] = numArray[curIndex];
        int s = simulation(curIndex+1, numPicked+1) + simulation(curIndex+1, numPicked);
        return s;
    }
}

int main(){
    scanf("%d%d%d", &numLeastPick, &numNum, &maximum);

    numArray = malloc(numNum * sizeof(int));
    pickedNumber = malloc(numNum * sizeof(int));

    for(int i = 0; i < numNum; i++){
        scanf("%d", numArray+i);
    }

    printf("%d", simulation(0, 0));
    
}