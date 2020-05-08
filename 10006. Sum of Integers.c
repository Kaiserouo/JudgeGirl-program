#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    int sum = 0, i;
    while(scanf("%d", &i) != EOF){
        sum += i;
    }
    printf("%d", sum);
}