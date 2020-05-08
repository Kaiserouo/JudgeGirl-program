#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
    // find size of a
    int n=1;
    while(1){
        if(a[n-1]==NULL)break;
        n++;
    }
    int currentList[k];
    for(int i=0; i<k; i++)currentList[i] = -1;

    for(int i=0; i<n; i++){
        int modK = A[i] % k;
        if(currentList[modK] == -1){   //< first one
            currentList[modK] = i;
            head[modK] = &(A[i]);
        }
        else{   //< not first, connect pointer
            a[ currentList[modK] ] = &(A[i]);
            currentList[modK] = i;
        }
    }

    for(int i=0; i<k; i++){
        if(currentList[i] != -1){
            a[ currentList[i] ] = NULL;
        }
    }
} 

int main(int argc, char const *argv[])
{
    int N, k;
    scanf("%d%d", &N, &k);
    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    int *a[N], *head[k];
    for (int i = 0; i < N-1; ++i)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for (int i = 0; i < k; ++i)
        head[i] = NULL;
    split(A, a, head, k);
    for (int i = 0; i < k; ++i) {
        if (head[i] == NULL)
            printf("NULL\n");
        else {
            int *tmp = head[i];
            printf("%d", *tmp);
            tmp = *(tmp-A+a);
            while (tmp != NULL) {
                printf(" %d", *tmp);
                tmp = *(tmp-A+a);
            }
            printf("\n");
        }
    }
    return 0;
}