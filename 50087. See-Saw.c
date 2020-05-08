#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
 
int FindBalancingPoint(int data[2048], int num_data){
    int torque;
    for(int pi = 0; pi < num_data; pi++){
        torque = 0;
        for(int i = 0; i < num_data; i++){
            torque += (i - pi) * data[i];
        }
        if(torque == 0){
            return pi;
        }
    }
    return -1;
}
void PrintSeq(int data[2048], int num_data, int balancing_point){
    for(int pi = 0; pi < num_data; pi++){
        if(pi == balancing_point){
            printf("v");
        }
        else{
            printf("%d", data[pi]);
        }
 
        printf("%c", pi == num_data-1 ? '\n' : ' ');
    }
}
void SwapSeq(int data[2048], int num_data, int steps){
    int tmp = data[steps - 1];
    data[steps - 1] = data[num_data - steps];
    data[num_data - steps] = tmp;
}
 
int main(){
    int data[2048];
    int num_data;
    scanf("%d", &num_data);
    for(int di = 0; di < num_data; di++){
        scanf("%d", &data[di]);
    }
 
    int steps = 1;
    int balancing_point = -1;
    while(steps <= ((num_data + 1) / 2)){ // max swaps possible for all natural numbers
        if((balancing_point = FindBalancingPoint(data, num_data)) != -1){
            PrintSeq(data, num_data, balancing_point);
            break;
        }
        else{
            SwapSeq(data, num_data, steps);
            steps++;
        }
    }
}