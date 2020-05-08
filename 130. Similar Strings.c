#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int similiar(char[], char[]);
 
int main(){
    char str1[100], str2[100];
    int n;
 
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s%s", str1, str2);
        printf("%s", similiar(str1, str2)? "yes" : "no");
        if(i!=n-1)printf("\n");
    }
}
 
int similiar(char str1[], char str2[]){
    int n1 = strlen(str1),
        n2 = strlen(str2);
    /* length equal */
    if(n1 == n2){
        if(!strcmp(str1, str2))return 1;    //< completely equal
        char str[100];
        for(int i=0; i<n1-1; i++){   //< check if swap similiar
            strcpy(str, str1);
            char tmp = str[i]; str[i] = str[i+1]; str[i+1] = tmp;   //< swap
            if(!strcmp(str, str2))return 1;
        }
    }
    /* length difference is 1 */
    else if(abs(n1 - n2) == 1){
        char big[100], small[100];
        if(n1>n2){   //< ensure which is big/small
            strcpy(big, str1);strcpy(small, str2);
        }
        else{
            strcpy(big, str2);strcpy(small, str1);
        }
        char str[100];
        int bigN = n1>n2?n1:n2;
        for(int i=0; i<bigN; i++){  //< for all element, delete and compare
            char str[81];
            strncpy(str, big, i);
            str[i] = '\0';
            if(i<bigN-1)strcat(str, &(big[i+1]));
            str[bigN-1] = '\0';
            if(!strcmp(str, small))return 1;
        }
    }
    /* all other senario */
    return 0;
 
 
}