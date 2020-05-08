#include <stdio.h>
#include <string.h>
#include <stdint.h>
enum {COMBINE, SEPERATE};

void test(unsigned long long int lli){
    char str[70];
    for(int i=0;i<64;i++)
    str[i] = lli%2LL + '0', lli/=2LL;
    for(int i=63; i>=0; i--){
        printf("%c", str[i]);
        if(i % 8 == 0)printf(" ");    
    }
    return;
}

int main(){
    unsigned long long int ULLI;
    unsigned int UI;
    unsigned short US;
    char C[10];
    char str[10];
    int mode;

    scanf("%d", &mode);
    switch(mode){
    case COMBINE:
        while(scanf("%s%u%hu%s", str, &UI, &US, C) != EOF){
            //printf("US = %hu\n", US);
            ULLI = 0LL;
            int flag = 0;
            for(int i=0; i<4; i++){
                switch (str[i]){
                case 'L':
                    ULLI <<= sizeof(unsigned int)*8;
                    ULLI += UI;
                    break;
                case 'S':
                    ULLI <<= sizeof(unsigned short)*8;
                    ULLI += US;
                    break;
                case 'C':
                    ULLI <<= sizeof(char)*8;
                    ULLI += !flag?C[0]:C[1];
                    flag++;
                    break;
                }
                //test(ULLI);printf("\n");
            }
            printf("%llu\n", ULLI);
        }
        break;
    case SEPERATE:
        while(scanf("%s%llu", str, &ULLI) != EOF){
            int flag = 0;
            UI = 0; US = 0; C[0] = 0; C[1] = 0;
            for(int i=3; i>=0; i--){
                switch (str[i]){
                case 'L':
                    UI = (unsigned int)ULLI;
                    ULLI >>= sizeof(unsigned int)*8;
                    break;
                case 'S':
                    US = (unsigned short)ULLI;
                    ULLI >>= sizeof(unsigned short)*8;
                    break;
                case 'C':
                    if(flag == 0)C[1]=(char)ULLI; else C[0]=(char)ULLI;
                    ULLI >>= sizeof(char)*8;
                    flag++;
                    break;
                }
            }
            C[2] = '\0';
            printf("%u %hu %s\n", UI, US, C);
            
        }
        break;
    }
}