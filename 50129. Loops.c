#include <stdio.h>
#include <stdlib.h>
void loops(int N, int *A, int *B[], int ans[4]){
    int mark[N];  //< mark if this element has been viewed
    for(int i=0; i<N; i++)mark[i] = 0;  //< initialization

    int maxL = -1, max = 0, minL = -1, min = 0;
    int curlength = 0,          //< current loop's data
        curmax = 0, curmin = 0;

    for(int i=0; i<N; i++){
        if(mark[i] != 0)continue; //< already been

        curlength = 0;
        curmax = A[i];
        curmin = A[i];
        int cur=i;

        while(mark[cur] == 0){
            mark[cur] = 1;
            curlength++;
            if(curmax < A[cur])curmax = A[cur];
            if(curmin > A[cur])curmin = A[cur];

            cur = B[cur] - A;
        }

        // update
        if(maxL == -1){
            maxL = minL = curlength;
            max = curmax; min = curmin;
        }
        else{
            if(minL >= curlength){
                min = minL==curlength?(min < curmin?min:curmin):(curmin);
                minL = curlength;
            }
            if(maxL <= curlength){
                max = maxL==curlength?(max > curmax?max:curmax):(curmax);
                maxL = curlength;
            }
        }
    }

    ans[0] = maxL;
    ans[1] = minL;
    ans[2] = max;
    ans[3] = min;

}
#define MAXN 1000000
int main(){
    int N;
    int *A = (int *)malloc(sizeof(int) * MAXN);
    int **B = (int **)malloc(sizeof(int *) * MAXN);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", A + i);
    for(int i = 0, ptr; i < N; i++){
        scanf("%d", &ptr);
        B[i] = A + ptr;
    }
    int ans[4];
    loops(N, A, B, ans);
    for(int i = 0; i < 4; i++)
        printf("%d\n", ans[i]);
    return 0;
}