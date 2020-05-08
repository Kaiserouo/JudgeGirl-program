#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

typedef struct {
    char name[32];
    int meso;
} Person;
char command_list[][40] = {"earns", "spends", "gives", "becomes"};
enum {EARNS, SPENDS, GIVES, BECOMES};
int find_command(char command[40]);
int find_user(Person *person, int numP, int user[2], int cmdNum, char user1[40], char user2[40]);
void print(Person *person, int numP);


int main(){
    int numP;
    scanf("%d", &numP);
    Person *person = malloc(numP * sizeof(Person));
    for(int i=0; i<numP; i++)
        scanf("%s%d", person[i].name, &person[i].meso);

    int money;
    char user1[40], user2[40], command[40];
    while(scanf("%s%s", user1, command) != EOF){
        int cmdNum = find_command(command);

        char input[40]; //< input
        scanf("%s", input);
        if(isdigit(input[0]))
            money = atoi(input);
        else strcpy(user2, input), scanf("%d", &money); 
        
        int user[2];
        int tmp_flag = find_user(person, numP, user, cmdNum, user1, user2);
        if(tmp_flag)continue;   //< invalid name or instruction

        int *tmp1, *tmp2;
        switch(cmdNum){
        case EARNS:
            (person+user[0])->meso += money;
            break;
        case SPENDS:
            tmp1 = &((person+user[0])->meso);
            if(*tmp1 >= money)*tmp1 -= money;
            break;
        case GIVES:
            tmp1 = &((person+user[0])->meso), tmp2 = &((person+user[1])->meso);
            if(*tmp1 >= money)*tmp1 -= money, *tmp2 += money;
            break;
        case BECOMES:
            (person+user[0])->meso = money;
            break;
        }
    }
    print(person, numP);
    free(person);
}

int find_command(char command[40]){
    for(int i=0; i<4; i++)
        if(strstr(command, command_list[i]) != NULL){
            return i;    
        }
    return -1;  //< for !found
}
int find_user(Person *person, int numP, int user[2], int cmdNum, char user1[40], char user2[40]){
    switch(cmdNum){
    case -1:
        return 1; 
        break;
    case EARNS:case SPENDS:case BECOMES:
        for(int i = 0,flag = 0; i<numP && flag<1; i++){
            if(!strcmp((person+i)->name, user1))
                user[0] = i, flag++;
            if(flag == 1)return 0;

        }
        break;
    case GIVES: 
        for(int i = 0,flag = 0; i<numP && flag<2; i++){
            if(!strcmp((person+i)->name, user1))
                user[0] = i, flag++;
            if(!strcmp((person+i)->name, user2))
                user[1] = i, flag++;
            
            if(flag == 2)return 0;
        }
        break;
    }
    return 1;
}
void print(Person *person, int numP){
    for(int i=0; i<numP; i++)
        printf("%s %d\n", (person+i)->name, (person+i)->meso);
}