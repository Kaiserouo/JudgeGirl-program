#include <stdio.h> 
void merge(int A[], int B[], int* a[], int* b[]){
    int i = 0,   //< index of array A
        j = 0;   //< index of array B
 
    //< find size of array
    int size_A = 1,
        size_B = 1;
    while(1){
        if(a[size_A-1] == NULL){
            break;
        }
        size_A++;
    }
    while(1){
        if(b[size_B-1] == NULL){
            break;
        }
        size_B++;
    }

    // run main procedure
    while ( !(i == size_A || j == size_B) ){  //< until one of them is sorted
        if(A[i] > B[j]){    //< B[j] is the smallest number of remaining numbers.
            b[j] = &A[i];
            j++;
        }
        else{
            a[i] = &B[j]; //< A[i] is the smallest number of remaining numbers.
            i++;
        }
    }

 //   if(i == size_A){         //< A sorted, connect remaining B
        for(int k=1; k<size_B; k++){
            if(b[k] == b[k-1]){
                b[k-1] = &B[k];
            }
        }
//    }
//    else if(j == size_B){    //< B sorted, connect remaining A
        for(int k=1; k<size_A; k++){
            if(a[k] == a[k-1]){
                a[k-1] = &A[k];
            }
//        }
    }
}

int main()
{
    int A[10], B[10];
    int *a[10], *b[10], *ans_a[10], *ans_b[10];
    int i, N, M;
 
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(i = 0; i < M; i++)
        scanf("%d", &B[i]);
    for(i = 0; i < N-1; i++)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for(i = 0; i < M-1; i++)
        b[i] = &B[i+1];
    b[M-1] = NULL;
 
    merge(A, B, a, b);
 
    ans_a[0] = &B[0]; ans_a[1] = &A[2]; ans_a[2] = &B[1]; ans_a[3] = &B[2];
    ans_b[0] = &A[1]; ans_b[1] = &A[3]; ans_b[2] = NULL;
 
    for(i = 0; i < N; i++){
        if(a[i] != ans_a[i])
            printf("a[%d] is Wrong!\n", i);
    }
    for(i = 0; i < M; i++){
        if(b[i] != ans_b[i])
            printf("b[%d] is Wrong!\n", i);
    }
    printf("Finish!\n");
    return 0;
}