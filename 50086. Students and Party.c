#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct{
    int friend[256];
    int num_friend;
} Students;

Students stu[32768];

void Initialize(Students stu[], int num_stu){
    for(int si = 0; si < num_stu; si++){
        stu[si].num_friend = 0;
    }
}

int main(){
    int num_stu = 0;
    scanf("%d", &num_stu);
    Initialize(stu, num_stu);
    int num_pair = 0;
    scanf("%d", &num_pair);
    for(int pi = 0; pi < num_pair; pi++){
        int x, y;
        scanf("%d%d", &x, &y);
        stu[x].friend[stu[x].num_friend] = y;
        stu[x].num_friend++;
        stu[y].friend[stu[y].num_friend] = x;
        stu[y].num_friend++;
    }
    int list_party[32768] = {0};
    int cur = 0;
    while(scanf("%d", &cur) != EOF){
        list_party[cur] = 1;
        for(int i = 0; i < stu[cur].num_friend; i++){
            list_party[stu[cur].friend[i]] = 1;
        }
    }
    for(int i = 0; i < num_stu; i++){
        if(!list_party[i])
            printf("%d\n", i);
    }
}