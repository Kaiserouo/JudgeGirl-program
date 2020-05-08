#include <stdio.h>
#define MAXN 1024
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    const int *ptr[1024][1024];  //< ptr array, [number in a] = pointer of that num in a

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ptr[ A[i][j]/N ][ A[i][j]%N ] = &(A[i][j]);
        }
    }

    for(int i=0; i<N; i++){ //< for all element in B
        for(int j=0; j<N; j++){
            int k = A[i][j] + 1;
            if( k != N*N )B[i][j] = ptr[ k/N ][ k%N ];
            else B[i][j] = ptr[0][0];
        }
    }
}
int A[MAXN][MAXN];
const int *B[MAXN][MAXN];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    constructPointerArray(A, B, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%c", *B[i][j], j == N - 1 ? '\n' : ' ');
        }
    }
    return 0;
}