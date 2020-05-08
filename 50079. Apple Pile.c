#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d\n", (a+b)*(b-a+1)/2, (b-a-1)*2+a+b);
}