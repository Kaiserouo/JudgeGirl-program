#include <stdio.h>

long long vA,vB,vC,nA,nB,nC;
long long value;
int aA,aB,aC;

int isValid(int a,int b,int c){
    if(a>nA || b>nB || c>nC)return 0;
    if((vA*a + vB*b + vC*c) > value)return 0;
    else if((vA*a + vB*b + vC*c) < value)
        return isValid(a+1,b,c) || isValid(a,b+1,c) || isValid(a,b,c+1);
    else if((vA*a + vB*b + vC*c) == value)
        return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%ld%d%d%d%d%d%d", &value, &nA, &nB, &nC, &vA, &vB, &vC);
        printf("%s", isValid(0,0,0)?"yes":"no");
        if(i!=n-1)putchar('\n');
    }
}