#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


int compare(const void *a, const void *b){
    char *ptr1 = (char *)a;
    char *ptr2 = (char *)b;
    return strcmp(ptr1, ptr2);
}


int main(){
    int num = 0;
    char str[100][100];
    while(fgets(str[num], 100, stdin) != NULL){
        num++;
    }
    qsort(str, num, sizeof(char) * 100, compare);
    for(int i = 0; i < num; i++){
        printf("%s", str[i]);
    }
}