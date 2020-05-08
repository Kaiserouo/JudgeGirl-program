#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fusion(char mainstr[], char addstr[]);

int main(){
    char str1[200], str2[200];

    scanf("%s", str1);
    while(scanf("%s", str2) != EOF){
        fusion(str1, str2);
    }
    printf("%s", str1);
}

void fusion(char mainstr[], char addstr[]){
    int mainN = strlen(mainstr),    //< length of string
        addN = strlen(addstr);
    int leastN = mainN > addN ? addN : mainN;   //< find min of length

    for(int i=leastN; i>0; i--){
        if(!strncmp(mainstr + (mainN - i), addstr, i)){ //< found first match
            strcat(mainstr, addstr + i);
            return;
        }
    }
    strcat(mainstr, addstr);

}