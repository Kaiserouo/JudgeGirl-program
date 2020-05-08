#include <stdio.h>

#define swap(a,b) {int tmp = a; a = b; b = tmp;}
int gcd(int a, int b){
    if(a < b)swap(a, b);
    for(int i = b; i >= 1; i--){
        if(a%i==0 && b%i==0)return i;
    }
}

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        if(a == 0){
            printf("0 / 1\n");continue;
        }
        int tmp = gcd(a, b);
        printf("%d / %d\n", a/tmp, b/tmp);
    }
    
}