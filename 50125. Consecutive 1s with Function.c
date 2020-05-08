#include <stdio.h>
#define MAXN 256
#define DEBUG 0

#if DEBUG == 1
int findLength (int array[][256], int N, int r, int c, int dr, int dc){
    int numCount = 0,
        biggestNumCount = 0;
    while(r<N && r >=0 && c<N && c >= 0){   //< in range
        if(array[r][c] == 0){
            biggestNumCount = (numCount>biggestNumCount)?numCount:biggestNumCount;
            numCount = 0;
        }
        else{
            numCount++;
        }
        r += dr;
        c += dc;
    }
    biggestNumCount = (numCount>biggestNumCount)?numCount:biggestNumCount;
            numCount = 0;

    return biggestNumCount;
}
#endif //DEBUG
void cmp(int *ptr, int a){
    if(*ptr < a)*ptr = a;
}
int main () {
    int array[MAXN][MAXN];
    int N, r, c;
    int direction[4][2] = {{1,0}, {1,1}, {0,1}, {-1,1}};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &array[i][j]);
    
    int biggestNum = 0;
    for(int i=0;i<N;i++){
        cmp(&biggestNum, findLength(array, N, i, 0, 0, 1)); //vertical
        cmp(&biggestNum, findLength(array, N, 0, i, 1, 0)); //horizontal
        cmp(&biggestNum, findLength(array, N, 0, i, 1, 1)); //down-right
        cmp(&biggestNum, findLength(array, N, i, 0, 1, 1)); //downward
        cmp(&biggestNum, findLength(array, N, 0, i, 1, -1)); //down-left
        cmp(&biggestNum, findLength(array, N, i, N-1, 1, -1)); //downward
    }
    printf("%d",biggestNum);
}