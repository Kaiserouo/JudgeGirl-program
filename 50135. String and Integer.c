#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

void strtoint(){
    char input[100001];
    scanf("%s", input);
    int len = strlen(input)+1;
    uint64_t num = 0LL;
    for(int i = 0; i < len; i++){
        uint64_t tmp = input[i];
        tmp <<= (7 - (i%8)) * 8;
        num+=tmp;

        if(i%8 == 7){
            printf("%lld\n", num);
            num = 0LL;
        }
    }
    if(len%8 != 0)printf("%lld\n", num);
}
void inttostr(){
    char output[100001] = "";
    int curlen = 0;
    uint64_t num;
    int tmp;
    scanf("%d", &tmp);
    while(tmp--){
        scanf("%lld", &num);
        for(int i = 7; i >= 0; i--){
            output[curlen] = (num >> (i*8)) & 255LL;
            curlen++;
        }
    }
    printf("%s", output);
}

int main(){
    int type;

    scanf("%d", &type);
    switch(type){
    case 0:
        strtoint();
        break;
    case 1:
        inttostr();
        break;
    }

}