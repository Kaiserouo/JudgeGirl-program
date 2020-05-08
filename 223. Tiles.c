#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int l, m;   //< given by problem
char plate[65][65] = {0};
int convert90[5] = {0, 2, 3, 4, 1};
int convertn90[5] = {0, 4, 1, 2, 3};
int put_0(int k){
    int tmp = 1<<(k-1);
    for(int i = 1; i < tmp; i++){
        for(int j = 1; j < tmp; j++){
            plate[i+tmp][j+tmp] = plate[i][j];
        }
    }
}
int put_90(int k){
    int tmp = 1<<(k-1);
    for(int i = 1; i < tmp; i++){
        for(int j = 1; j < tmp; j++){
            plate[j+tmp][tmp-i] = convert90[plate[i][j]];
        }
    }
}
int put_n90(int k){
    int tmp = 1<<(k-1);
    for(int i = 1; i < tmp; i++){
        for(int j = 1; j < tmp; j++){
            plate[tmp-j][tmp+i] = convertn90[plate[i][j]];
        }
    }
}
int place(int i){
    if(1<<i > 64)return 0;
    put_0(i);
    put_90(i);
    put_n90(i);
    plate[1<<(i-1)][1<<(i-1)] = 1;
    place(i+1);
}
void output(){
    /*for(int i=0; i<65; i++){
        for(int j=0; j<65; j++){
            printf("%d ", plate[i][l-j]);
        }
        printf("\n");
    }*/
    for(int i = 0; i <= l; i++){
        for(int j = 0; j <= l; j++){
            if(i<m && j<m)continue;
            if(i == l && j == l)continue;
            if(plate[i][j]!=0)printf("%d %d %d\n", plate[i][j], l-j, l-i);
        }
    }
    
    return;
}

int main(){    
    scanf("%d%d", &l, &m);
    place(1);
    output();
    /*while(scanf("%d%d", &l, &m)!=EOF){
        printf("%d\n", plate[l][m]);
    }*/
}