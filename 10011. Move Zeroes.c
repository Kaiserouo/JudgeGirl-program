#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100005
int A[MAXN];
int main() {
    int n, i;
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
        
        int *b = malloc(n*sizeof(int));
        int count = 0;
        for(int i = 0; i < n; i++){
            if(A[i])   b[count++] = A[i]; 
        }

        for (i = 0; i < n; i++)
            printf("%d%c", i<count?b[i]:0, " \n"[i==n-1]);
    }
    return 0;
}