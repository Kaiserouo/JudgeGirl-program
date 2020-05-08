#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

char input[100001];
char output[2][100001] = {0};
int curOutNum = 0;  // after while, encode index of string ready to output.
int curDealNum = 1;
int hasPrinted = 0;

void merge(char *input, char *lastchar, char *output){
    // terminal
    if(*input == '\0'){
        strcat(output, lastchar);
        return;
    }else if(*lastchar == '\0'){
        strcat(output, input);
        return;
    }

    if(strncmp(input, lastchar, 3) > 0){    // input bigger
        strncat(output, lastchar, 3);
        output[3] == '\0';
        merge(input, lastchar+3, output+3);
    }else{                              // lastchar bigger
        strncat(output, input, 3);
        output[3] == '\0';
        merge(input+3, lastchar, output+3);
    }
    return;
}

int main(){
    while(scanf("%s", input) != EOF){
        output[curOutNum][0] = '\0';
        merge(input, output[curDealNum], output[curOutNum]);
        if(hasPrinted == 0)hasPrinted = 1;
        else printf("%s\n", output[curOutNum]);
        curDealNum = curOutNum;
        curOutNum = curOutNum == 0 ? 1 : 0;
    }
}