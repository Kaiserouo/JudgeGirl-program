#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 10005

/* structure */
typedef struct {
    unsigned int id;
    char name[32];
} Person;
typedef struct {
    unsigned id1;
    unsigned id2;
} Friends;

/* global */
Person person[MAXN];
Friends friend[MAXN];
int numPerson, numFriend;

/* function */
int initialization(FILE *fp){
    fread(&numPerson, 4, 1, fp);
    fread(person, sizeof(Person), numPerson, fp);    
    fread(&numFriend, 4, 1, fp);
    fread(friend, sizeof(Friends), numFriend, fp);    
    
}
int isInFriend(int id[2], Friends f){
    return (id[0] == f.id1 || id[0] == f.id2)&&(id[1] == f.id1 || id[1] == f.id2) ? 1 : 0;
}
void find_id(char s[2][50], int id[2]){
    int flag = 0;
    for(int i = 0; i < numPerson && flag < 2; i++){
        for(int j = 0; j < 2; j++){
            if(!strcmp(s[j], person[i].name))   id[flag++] = person[i].id; 
        }
    }
    return;
}
int print(){
    printf("%d, %d\n", numPerson, numFriend);
    for(int i = 0; i < numPerson; i++){
        printf("%d %s\n", person[i].id, person[i].name);
    }
    printf("\n");
    for(int i = 0; i < numFriend; i++){
        printf("%d %d\n", friend[i].id1, friend[i].id2);
    }
}

/* main */
int main(){
    FILE *fin = fopen("friends", "rb");
    assert(fin != NULL);
    initialization(fin);

    char input[100];
    char s[2][50];
    int id[2];
    while(1){
        fgets(input, 100, stdin);
        if(!strcmp(input, "end\n")) break;
        sscanf(input, "%s%s", s[0], s[1]);
        find_id(s, id);
        int flag = 0;
        for(int i = 0; i < numFriend && flag == 0; i++){
            if(isInFriend(id, friend[i]))
                printf("yes\n"), flag = 1;
        }
        if(flag == 0)   printf("no\n");
    }
}