#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

char firstChar;
int maxLen;
int maxDist;
int maxPrint;
int curPrint = 0;
char *str;  // store output string

int compare(const void *a, const void *b){
    return *(char *)a - *(char *)b;
}

int build(char *str, int i){
    // terminal
    if(i == maxLen){
        printf("%s\n", str);
        curPrint++;
        if(curPrint == maxPrint)    exit(0);
        return 0;
    }

    char availChar[maxDist];
    for(int j = 0; j < maxDist; j++){
        availChar[j] = ((str[i-1] - 'a' + j+1) % 26) + 'a';
    }
    qsort(availChar, maxDist, sizeof(char), compare);
    for(int j = 0; j < maxDist; j++){
        str[i] = availChar[j];
        build(str, i+1);
    }
    return 0;
}

int main(){
    scanf("%c%d%d%d", &firstChar, &maxDist, &maxLen, &maxPrint);
    str = calloc(maxLen, sizeof(char));
    str[0] = firstChar;
    str[maxLen] = '\0';
    build(str, 1);
}