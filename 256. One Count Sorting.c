#include <stdio.h>
#include <stdlib.h>

typedef struct number{
    long long int num;
    int one;
} Number;

int count_one(Number n[1002], int count){
    for(int i = 0; i < count; i++){
        n[i].one = __builtin_popcountll(n[i].num);
    }
}

int compare(const void *a, const void *b){
    Number *ptr1 = (Number *)a;
    Number *ptr2 = (Number *)b;
    if(ptr1->one > ptr2->one)return 1;
    else if(ptr2->one > ptr1->one)return -1;
    else if(ptr1->num > ptr2->num)return 1;
    else if(ptr2->num > ptr1->num)return -1;
    else return 0;
}

int main(){
    Number n[1002];
    int count = 0;
    while(scanf("%lld", &((n + count)->num)) != EOF){
        count++;
    }
    count_one(n, count);
    qsort(n, count, sizeof(Number), compare);
    for(int i = 0; i < count; i++){
        printf("%lld\n", (n+i)->num);
    }
}
