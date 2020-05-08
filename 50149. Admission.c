#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct{
    int id;
    int sub[5];
    int total;
} Student;

int compare(const void *a, const void *b){
    Student *ptr1 = (Student *)a;
    Student *ptr2 = (Student *)b;
    int list[5] = {2, 1, 3, 0, 4};
    if(ptr1->total > ptr2->total)   return -1;
    else if(ptr1->total < ptr2->total)   return 1;
    else {
        for(int i = 0; i < 5; i++){
            if(ptr1->sub[list[i]] > ptr2->sub[list[i]]) return -1;
            else if(ptr1->sub[list[i]] < ptr2->sub[list[i]]) return 1;
        }
        if(ptr1->id < ptr2->id)   return -2;
        else if(ptr1->id > ptr2->id)   return 2;
    }
    return 0;
}

int main(){
    int num, numsub;
    scanf("%d%d", &numsub, &num);
    Student stu[num];
    for(int i = 0; i < num; i++){
        int id, sub[5];
        scanf("%d%d%d%d%d%d", &id, sub, sub+1, sub+2, sub+3, sub+4);
        stu[i].id = id;
        stu[i].total = 0;
        for(int j = 0; j < 5; j++)  stu[i].sub[j] = sub[j], stu[i].total += sub[j];
    }
    qsort(stu, num, sizeof(Student), compare);
    for(int i = 0; i < numsub; i++){
        printf("%d\n", stu[i].id);
    }
    int index = numsub;
    if(!index)  return 0;
    while(compare((void *)&stu[index-1], (void *)&stu[index]) == -2){
        printf("%d\n", stu[index].id);
        index++;
    }
}