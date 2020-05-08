#include <stdio.h>
#include <stdlib.h>

#define loc(a,b) (a*m+b)
enum {X, Y};
int pos[1000*1000][2];
void output(int n, int m, int lx, int ly, int rx, int ry, char *c){
    int num = 0;
    for(int i = lx; i <= rx; i++)
    for(int j = ly; j <= ry; j++){
        if(*(c+loc(i, j)) == 0){
            pos[num][X] = i+1, pos[num++][Y] = j+1;
            *(c+loc(i, j)) = 1;
        }
    }
    printf("%d", num);
    for(int i = 0; i < num; i++){
        printf(" (%d, %d)", pos[i][X], pos[i][Y]);
    }
    putchar('\n');
}
int main(){
    int n, m;   //< row x column
    int lx, ly, rx, ry;
    int numInquire;
    scanf("%d%d%d", &n, &m, &numInquire);
    char *c = calloc(n*m, sizeof(char));
    while(numInquire--){
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        output(n, m, --lx, --ly, --rx, --ry, c);
    }
    free(c);
}