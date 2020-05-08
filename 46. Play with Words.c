#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEBUG 0

#define INSERT 0
#define DELETE 1
#define LEFT -1
#define RIGHT -2

/* function header */
void initInput(char input[], char word[][20], int *state, int *num, char c[]);
void insert(char str[], int n, int state, char c[]);
void delete(char str[], int n, int state);
void print(char str[], int n);
void turnToDigit(char tmp[], int *num);

int main(){
    char str[10005] = "",
        input[20] = "",
        word[2][20] = {"insert", "delete"};
        
    int n = 0;
    int state,  //< insert = 0, delete = 1
        num;    //< left = -1, right = -2
    char c[3];    //< c is char to insert

    while(scanf("%s", input) != EOF){
        
        initInput(input, word, &state, &num, c);

        switch(state){
        case INSERT:
            insert(str, n, num, c);
            n++;
            break;
        case DELETE:
            delete(str, n, num);
            n--;
        }
    }
    
    print(str, n);
}

/* function */
void initInput(char input[], char word[][20], int *state, int *num, char c[]){
    for(int i=0; i<2; i++){
        if(!strcmp(input, word[i]))*state = i;
    }
    char tmp[20];
    scanf("%s", tmp);
    if(isdigit(tmp[0])){
        turnToDigit(tmp, num);
    }
    else{
        if(!strcmp(tmp, "left"))*num = LEFT;
        else if(!strcmp(tmp, "right"))*num = RIGHT;
        else *num = -3;  //< default cond.
    }
    
    if(*state == INSERT)scanf("%s", c);
}
void insert(char str[], int n, int num, char c[]){
    char tmp[n+10];
    tmp[0] = '\0';
    if(n==0)strcpy(str, c);
    else if(n>0) switch(num){
    case LEFT:
        strcpy(tmp, str);
        strcpy(str, c);
        strcat(str, tmp);
        break;
    case RIGHT:
        strcat(str, c);
        break;
    default:
        strcpy(tmp, &(str[num-1]));
        str[num-1] = '\0';
        strcat(str, c);
        strcat(str, tmp);
    }

    return;
}
void delete(char str[], int n, int num){
    char empty[n+10];
    empty[0] = '\0';
    
    if(n>0)switch(num){
    case LEFT:
        strcpy(empty, &(str[1]));
        strcpy(str, empty);
        break;
    case RIGHT:
        str[n-1] = '\0';
        break;
    default:
        str[num-1] = '\0';
        strcpy(empty, &(str[num]));
        strcat(str, empty);
    }
    return;
}
void print(char str[], int n){

#if DEBUG == 0
    int curlength = 0,
        longest = 0,
        storedNum = 0,
        cNum[n];
    char cur = '0',
        c[n];
    if(n == 0){
        printf("0");
        return;
    }
    for(int i=0; i<n; i++){
        if(cur == str[i]){
            curlength++;
        }
        else if(curlength > 0){
            c[storedNum] = cur;
            cNum[storedNum] = curlength;
            longest = longest<curlength ? curlength : longest;
            cur = str[i];
            curlength = 1;
            storedNum++;
        }
        else{   //starting
            cur = str[i];
            curlength = 1;
        }
    }
    //last strip of string
    if(curlength > 0){
        c[storedNum] = cur;
        cNum[storedNum] = curlength;
        longest = longest<curlength ? curlength : longest;
        storedNum++;
    }

    for(int i=0; i<storedNum; i++){
        if(cNum[i] == longest)printf("%c ", c[i]);
    }printf("%d", longest);

#elif DEBUG == 1
    printf("%s", str);
#endif
    return;
}
void turnToDigit(char tmp[], int *num){
    int n = strlen(tmp);
    *num = 0;
    int ten = 1;
    for(int i=n-1; i>=0; i--){
        *num += (tmp[i]-'0')*ten;
        ten *= 10;
    }
    return;
}