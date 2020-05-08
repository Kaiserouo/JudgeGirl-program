#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main(){
    char k[101];
    int size = 0;
    char c;
    while((c = getchar())!=EOF){
        k[size] = c; size++;
    }
        int start=0,end=size-1;
        for(int i=0;i<size;i++){
            if(!isspace(k[i])){
                start=i;
                break;
            }
        }
        for(int i=size-1;i>=0;i--){
            if(!isspace(k[i])){
                end=i;
                break;
            }
    }
 
    for(int i=start;i<=end;i++){
        printf("%c",k[i]);
    }
    
    
    printf("\n");
    
}