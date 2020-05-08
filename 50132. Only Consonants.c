#include <stdio.h>
#include <string.h>

int main(){
    char str[40];
    int count = 0;
    char last = 125;
    while(scanf("%s", str) != EOF){
        char *start = strtok(str, "aeiou");
        while(start != NULL){
            while(*start != '\0'){
                if(last < *start)count++;
                last = *start;
                start++;
            }
            start = strtok(NULL, "aeiou");
        }
    }
    printf("%d", count);
}