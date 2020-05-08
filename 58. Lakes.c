#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#define loc(a,b) a*m+b
int n, m;  
char *c;
int *size;
int numLake = 0;
int clearLake(int i, int j){
    if(i<0 || j<0 || i>n-1 || j>m-1)return 0;
    if( !*(c+loc(i,j)) )return 0;
    *(c+loc(i,j)) = 0;
    return 1+clearLake(i,j-1)+clearLake(i,j+1)+clearLake(i+1,j)+clearLake(i-1,j);
}
int compare(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}
int main(){
    scanf("%d%d", &n, &m);
    c = calloc(n*m, sizeof(char));
    size = calloc(n*m/2+1, sizeof(int));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", c+loc(i,j));
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(*(c+loc(i,j)))
                size[numLake++] = clearLake(i,j);
        }
    }
    qsort(size, numLake, sizeof(int), compare);
    for(int i = 0; i < numLake; i++){
        printf("%d\n", size[i]);
    }
}