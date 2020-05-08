#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define loc(a,b) (a*2+b)
int numCountry, numColor, numAdjacent;
char *adj;
char *country;
int print(){
    for(int i = 0; i < numCountry; i++){
        printf("%d\n", country[i]);
    }
    exit(0);
}
int check(int i){
    for(int j = 0; j < numAdjacent; j++){
        if(*(adj+loc(j,0)) <= i && *(adj+loc(j,1)) <= i && (country[*(adj+loc(j,0))] == country[*(adj+loc(j,1))]))
            return 0;
    }
    return 1;
}

int simulation(int i){
    if(i==numCountry)
        if(check(i)) print();
        else return 0;
    else for(int j = 1; j <= numColor; j++){
        country[i] = j;
        if(check(i)){
            simulation(i+1);
        }
    }
}

int main(){
    scanf("%d%d%d", &numCountry, &numColor, &numAdjacent);
    adj = calloc(numAdjacent * 2, sizeof(char));
    country = calloc(numCountry, sizeof(char));
    for(int i = 0; i < numAdjacent; i++)    scanf("%d%d", adj+loc(i,0), adj+loc(i,1));
    simulation(0);  printf("no solution.\n");
}