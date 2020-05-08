#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

void input(char *stream, int num_bit){
    char c;
    for(int i = 0; i < num_bit; i++){
        c = fgetc(stdin);
        stream[i] = fgetc(stdin) - '0';
    }
}
int fit_cond(char *stream1, char *stream2, int num_bit){
    int count;
    for(int i = 0; i < num_bit; i++){
        if()
    }
}

int main(){
    int num_str, num_bit;
    while(scanf("%d%d", &num_str, &num_bit) != EOF){
        char stream[num_str][num_bit];
        int fits_cond, num_all;
        for(int i = 0; i < num_str; i++){
            input(stream[i], num_bit);
            for(int j = 0; j < i; j++){
                num_all++;
                if(fit_cond(stream[i], stream[j], num_bit)){
                    fits_cond++;
                }
            }
        }
        printf("%lf\n", (double)fits_cond / num_all);
    }
}