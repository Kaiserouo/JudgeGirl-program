#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[200];
    char word[8][200] = {"of", "the", "and", "at", "of.", "the.", "and.", "at."};
    while(scanf("%s", str) != EOF){
        int flag = 0;
        for(int i=0;i<8;i++){
            if(!strcmp(str,word[i]))flag = 1;
        }

        if(!flag){
            printf("%c", toupper(str[0]));
        }

        if(strchr(str, '.') != NULL){
            printf("\n");
        }
    }
}