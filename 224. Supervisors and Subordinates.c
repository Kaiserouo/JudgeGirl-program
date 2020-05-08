#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

struct employee{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};
typedef struct employee Employee;

// malloc storage to Employee pointer
void init_storage(Employee **storage, int n){
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
// free Employee pointer and set to NULL
void free_storage(Employee **storage){
    free(*storage);
    *storage = 0;
}
// given Employee set and numEmp, find Employee by id
Employee* find_employee_by_id( Employee *set, int n, int id ){
    for(int i = 0; i < n; i++){
        if(set[i].id == id) return set+i;
    }
    return NULL;
}
// given Employee set and numEmp, find Employee by name
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
    for(int i = 0; i < n; i++){
        if(!strcmp(first_name, set[i].first_name) && !strcmp(last_name, set[i].last_name)) return set+i;
    }
    return NULL;
}
// find root
Employee* find_root_boss( Employee *set, int n, Employee *employee ){
    Employee *prev = NULL;
    Employee *cur = employee;
    while(prev != cur){
        prev = cur;
        cur = find_employee_by_id(set, n, cur->boss_id);
    }
    return cur;
}
// check relationship, {1:subordinate, 2:supervisor, 3:colleague, def:unrelated}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    Employee *a_boss, *b_boss;
    a_boss = find_root_boss(set, n, A);
    b_boss = find_root_boss(set, n, B);
    if(a_boss != b_boss) return 0;  // unrelated
    else{   // same row
        Employee *prev = NULL;
        Employee *a_tmp = A;
        while(a_tmp != NULL && a_tmp != B && a_tmp != prev){
            prev = a_tmp;
            a_tmp = find_employee_by_id(set, n, a_tmp->boss_id);
        }
        if(a_tmp == B) return 1;    // subordinate

        Employee *b_tmp = B;
        while(b_tmp != NULL && b_tmp != A && b_tmp != prev){
            prev = b_tmp;
            b_tmp = find_employee_by_id(set, n, b_tmp->boss_id);
        }
        if(b_tmp == A) return 2;    // supervisor

        return 3;   // colleague
    }
}
 

/* main given */
int main()
{
    int n, m;
    int i;
    Employee *set = NULL;
 
    scanf("%d", &n);
    init_storage(&set, n);
    for ( i = 0 ; i < n ; i++ )
        scanf("%d %s %s %d", &(set[i].id), set[i].first_name, set[i].last_name, &(set[i].boss_id));
    char first_name_A[32], first_name_B[32];
    char last_name_A[32], last_name_B[32];
    Employee *A, *B;
    int type;
 
    scanf("%d", &m);
    for ( i = 0 ; i < m ; i++ )
    {
        scanf("%s %s", first_name_A, last_name_A);  
        A = find_employee_by_name(set, n, first_name_A, last_name_A);
 
        scanf("%s %s", first_name_B, last_name_B);  
        B = find_employee_by_name(set, n, first_name_B, last_name_B);
 
        type = check_relationship(set, n, A, B);
        switch(type){
            case 1:
                printf("subordinate\n"); break;
            case 2:
                printf("supervisor\n"); break;
            case 3:
                printf("colleague\n"); break;
            default:
                printf("unrelated\n"); break;
        }
    }
    free_storage(&set);
    return 0;
}