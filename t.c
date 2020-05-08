#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

char *Infix2Postfix(char *infix_str){
    char *postfix_str = malloc((strlen(infix_str) + 1) * sizeof(char));
    // ...
}

double ComputePostfix(char *postfix_str){
    // ...
}

double Calculate(char *str){
    char *postfix_str = Infix2Postfix(str);
    double result = ComputePostfix(postfix_str);
    free(postfix_str);
    return result;
}

int main(){
    char str[100];
    scanf("%s", str);
    double result = Calculate(str);
    printf("%f", result);
}