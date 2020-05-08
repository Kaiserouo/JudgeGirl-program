#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct
{
    char lastname[81];
    char firstname[81];
    char id[81];
    int salary;
    int age;
} Data;

enum{EQUAL, NOTEQUAL, BIGGER, SMALLER};
enum{LASTNAME, FIRSTNAME, ID, SALARY, AGE};
enum{STRING, INT};
char fieldName[][10] = {"lastname", "firstname", "ID", "salary", "age"};
char operatorName[][10] = {"==", "!=", ">", "<"};

int find(char tmp[], char name[][10], int size){
    for(int i=0; i<size; i++){
        if(!strcmp(tmp, name[i]))return i;
    }
}
int cond(Data *d, int condField, int condOpr, int condType, char condStr[]){
    char tmp[81];
    int tmpi;
    switch(condType){
    case STRING: 
        switch(condField){
        case LASTNAME:strcpy(tmp, d->lastname);break;
        case FIRSTNAME:strcpy(tmp, d->firstname);break;
        case ID:strcpy(tmp, d->id);break;
        }
        switch(condOpr){
        case EQUAL:
            return !strcmp(tmp, condStr)?1:0;
        case NOTEQUAL:
            return strcmp(tmp, condStr)?1:0;
        }
        break;

    case INT:
        switch(condField){
        case SALARY:tmpi = d->salary;break;
        case AGE:tmpi = d->age;break;
        }
        switch(condOpr){
        case EQUAL: return tmpi==atoi(condStr);
        case BIGGER: return tmpi>atoi(condStr);
        case SMALLER: return tmpi<atoi(condStr);
        }
    }
}
void printData(Data *d, int field[], int numField){
    for(int i=0; i<numField;i++){
        switch(field[i]){
        case FIRSTNAME:printf("%s%c", d->firstname, i==numField-1?'\n':' ');break;
        case LASTNAME:printf("%s%c", d->lastname, i==numField-1?'\n':' ');break;
        case ID:printf("%s%c", d->id, i==numField-1?'\n':' ');break;
        case SALARY:printf("%d%c", d->salary, i==numField-1?'\n':' ');break;
        case AGE:printf("%d%c", d->age, i==numField-1?'\n':' ');break;
        }
    }
}
void sel(Data data[50], int n){
    static int counter = 0;
    counter++;
    char tmp[20];
    int field[20], numField = 0;
    scanf("%s", tmp);
    
    // scan all field
    while(strcmp(tmp, "where")){
        field[numField++] = find(tmp, fieldName, 5);
        scanf("%s", tmp);
    }
//printf("field[] (%d) = ", numField);for(int i=0;i<numField;i++)printf("%d%c", field[i], i==numField-1?'\n':' ');
    //condition
    scanf("%s", tmp);   //< first operand
    int condField = find(tmp, fieldName, 5);
    int condType = condField<3 ? STRING : INT;
    scanf("%s", tmp);   //< operator
    int condOpr = find(tmp, operatorName, 4);

    scanf("%s", tmp);   //< second operator
    for(int i=0; i<n; i++){
        if(cond(&data[i], condField, condOpr, condType, tmp))
            printData(&data[i], field, numField);   
    }
}

int main(){
    Data data[50];
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s%s%s%d%d", data[i].lastname, data[i].firstname, data[i].id, &data[i].salary, &data[i].age);
    }
    
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++)
        sel(data, n);

}