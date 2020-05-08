#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

char str[3][9];
char try[3][9];
int try_num[3];
int numSymbol = 0;
char appearedSymbol[26];    // num -> first #i char found
int symbolNumber[26];  // char of uppercase -> its number, -1: not in list

int initialization(){
    for(int i=0; i<3; i++)  strcpy(try[i], str[i]);

    memset(symbolNumber, -1, 26*sizeof(int));
    
    for(int i = 0; i < 3; i++){ // gather alphabet
        int index = 0;
        while(str[i][index] != '\0'){
            if(isalpha(str[i][index])){
                if(symbolNumber[ str[i][index]-'A' ] == -1)
                    appearedSymbol[numSymbol++] = str[i][index], symbolNumber[ str[i][index]-'A' ] = 0;;
            }
            index++;
        }
    }

}
int check(){
    for(int i=0; i<3; i++){
        strcpy(try[i], str[i]);
        int index = 0;
        while(try[i][index] != '\0'){
            if(isalpha( try[i][index] )){
                try[i][index] = '0' + symbolNumber[try[i][index]-'A'];
            }
            index++;
        }
        try_num[i] = atoi(try[i]);
    }
    if(try_num[0] * try_num[1] == try_num[2])   return 1;
    else    return 0;
}
int simulation(int i){
    if(i == numSymbol){
        if(check())return 1;
        else return 0;
    }
    else{
        for(int j = 0; j <= 9; j++){
            symbolNumber[ appearedSymbol[i]-'A' ] = j;
            if(simulation(i+1))return 1;
        }
        return 0;
    }
}
int main(){
    scanf("%s%s%s", str[0], str[1], str[2]);
    initialization();
    if(simulation(0))   printf("%s x %s = %s\n", try[0], try[1], try[2]);
    else printf("what.");
}