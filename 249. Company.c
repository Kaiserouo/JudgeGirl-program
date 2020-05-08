#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef struct {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
} Employee;
int numEmp = 0;

enum{FIRST, LAST};
enum{NUM, DATA};

void scan_empdata(Employee emp[32]);
void find_boss_list(Employee emp[32], int bosslist[32][33], int idToBoss[32][2]);
void find_emp_id(Employee emp[32], char name[2][2][32], int inputID[2]);
void find_relation(Employee emp[32], int bosslist[32][33], int inputID[2]);
void make_id_to_bossid_array(Employee emp[32], int idToBoss[32][2]);

/*  main  */
int main(){
    Employee emp[32];
    
    scanf("%d", &numEmp);
    scan_empdata(emp);
    int bosslist[32][33] = {0};    //[person][bosslist], stopping at INT32_MIN
    int idToBoss[32][2] = {0};
    make_id_to_bossid_array(emp, idToBoss);
    find_boss_list(emp, bosslist, idToBoss);

    int numInput;
    scanf("%d", &numInput);
    for(int i=0; i<numInput; i++){
        char name[2][2][32];
        int inputID[2];
        scanf("%s%s%s%s", name[0][FIRST], name[0][LAST], name[1][FIRST], name[1][LAST]);
        find_emp_id(emp, name, inputID);
        find_relation(emp, bosslist, inputID);
    }
}

/* function */

/* input data */
void scan_empdata(Employee emp[32]){
    for(int i=0; i<numEmp; i++)
        scanf("%d%s%s%d", &emp[i].id, &emp[i].first_name, &emp[i].last_name, &emp[i].boss_id);
    return;
}
/* find everyones boss list */
void find_boss_list(Employee emp[32], int bosslist[32][33], int idToBoss[32][2]){
    for(int i=0; i<numEmp; i++){    //< for every employee
        int curEmp = emp[i].boss_id;
        bosslist[i][0] = emp[i].boss_id;
        bosslist[i][1] = -1;
        for(int j=1; j<32; j++){    //< for every persons boss
            for(int k=0, flag = 0; k<numEmp; k++)   //< find next boss
                if(idToBoss[k][0] == curEmp && flag == 0)curEmp = idToBoss[k][1], flag = 1;
            if(curEmp == bosslist[i][j-1])break;
            else bosslist[i][j] = curEmp, bosslist[i][j+1] = -1;
        }
    }
}
/* given two input name, find id of these two */
void find_emp_id(Employee emp[32], char name[2][2][32], int inputID[2]){
    for(int i=0, flag = 0; i<numEmp || flag<1; i++){
        for(int j=0; j<2; j++)
            if(!strcmp(emp[i].first_name, name[j][FIRST]) && !strcmp(emp[i].last_name, name[j][LAST]))
                inputID[j] = i, flag++;
    }
}
/* find 2 peoples relation: first one is second one's ...? */
void find_relation(Employee emp[32], int bosslist[32][33], int inputID[2]){
    // supervisor or subordinate
    for(int i=0; bosslist[ inputID[0] ][i] != -1; i++){
        if(bosslist[ inputID[0] ][i] == emp[inputID[1]].id){
            printf("subordinate\n");return;
        }
    }
    for(int i=0; bosslist[ inputID[1] ][i] != -1; i++){
        if(bosslist[ inputID[1] ][i] == emp[inputID[0]].id){
            printf("supervisor\n");return;
        }
    }
    //colleague
    for(int i=0; bosslist[ inputID[1] ][i] != -1; i++){
        for(int j=0; bosslist[ inputID[0] ][j] != -1; j++){
            if(bosslist[ inputID[1] ][i] == bosslist[ inputID[0] ][j]){
                printf("colleague\n");return;
            }
        }
    }
    printf("unrelated\n");return;
}
/* make array to only store everyones id and boss_id */
void make_id_to_bossid_array(Employee emp[32], int idToBoss[32][2]){
    for(int i=0; i<numEmp; i++)
        idToBoss[i][0] = emp[i].id, idToBoss[i][1] = emp[i].boss_id;
    return;
}
