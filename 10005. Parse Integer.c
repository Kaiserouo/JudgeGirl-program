#include <stdio.h> 
#include <string.h>    // strlen(s)
#include <ctype.h>
#include <stdlib.h>
 
int main() {
    char s[1024];
    while (scanf("%s", s) == 1) {
        int len = strlen(s) + 1;
        char num[1024];
        int isRecording = 0;
        int startZero = 0;
        memset(num, 0, 1024);
        for(int i=0; i<len; i++){
            if(!isdigit(s[i])){
                if(!isRecording){
                    continue;
                }else{
                    printf("%d\n", atoi(num));
                    memset(num, 0, 40);
                    isRecording = 0;
                }
            }else{
                    isRecording = 1;
                    char tmp[2]; tmp[0] = s[i], tmp[1] = '\0';
                    strcat(num, tmp);
            }
        }
    }
    return 0;
}