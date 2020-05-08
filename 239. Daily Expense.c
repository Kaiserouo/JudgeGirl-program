#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define cmp(ptr) ((ptr)->y * 10000 + (ptr)->m * 100 + (ptr)->d)

typedef struct{
    long long int y, m, d;
    char name[33];
    int amount;
} Expense;

int compare(const void *a, const void *b){
    Expense *ptr1 = (Expense *)a;
    Expense *ptr2 = (Expense *)b;

    int tmp_str_cmp = 0;
    if(cmp(ptr1) < cmp(ptr2)) return -1;
    else if(cmp(ptr1) > cmp(ptr2)) return 1;
    else return strcmp(ptr1->name, ptr2->name);
}

int output(Expense exp[], int num){
    int i = 1;
    int amount = exp[0].amount;
    Expense *last = exp;
    while(i <= num){
        if(i == num){
            printf("%lld %lld %lld %s %d\n", last->y, last->m, last->d, last->name, amount);
            break;
        }
        if(!compare(exp + i, last)){
            amount += exp[i].amount;
        }
        else{
            printf("%lld %lld %lld %s %d\n", last->y, last->m, last->d, last->name, amount);
            amount = exp[i].amount;
        }
        last = exp + i;
        i++;
    }
}

int main(){
    int num = 0;
    Expense *exp = malloc(10001 * sizeof(Expense));
    while((scanf("%lld %lld %lld %s %d", &exp[num].y, &exp[num].m, &exp[num].d, exp[num].name, &exp[num].amount)) != EOF){
        num++;
    }
    qsort(exp, num, sizeof(Expense), compare);
    output(exp, num);
    free(exp);
}