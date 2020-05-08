#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *given, *output[3];    // given string and output string
int s[2];   // given int: index of output
int len;    // length of given string
int curIndex;  // current processing index

void initialize_space(){
    given = malloc(10002);
    output[0] = malloc(10002);
    output[1] = malloc(10002);
    output[2] = malloc(10002);
    return;
}
int isvowel(char c){
    if(strchr("aeiou", c) != NULL)return 1;
    else return 0;
}
void put_char(int i){
    // final process
    if(given[i] == '\0'){
        output[0][i] = output[1][i] = output[2][i] = '\0';
        return;
    }

    output[0][i] = s[0]==curIndex ? given[i] : '+';
    output[1][i] = s[1]==curIndex ? given[i] : '+';
    output[2][i] = s[0]==curIndex || s[1]==curIndex ? '+' : given[i];

    if(isvowel(given[i]))   curIndex++;
}
int main(){
    initialize_space();

    while(scanf("%s%d%d", given, &s[0], &s[1]) != EOF){
        len = strlen(given)+1;  // to also process '\0'
        curIndex = 0;
        for(int i = 0; i < len; i++){
            put_char(i);
        }
        printf("%s\n%s\n%s\n", output[0], output[1], output[2]);
    }
}