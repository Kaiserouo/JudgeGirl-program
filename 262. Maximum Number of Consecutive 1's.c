#include <stdio.h>

int main(){
    int input;
    while(scanf("%d", &input) != EOF){
        int count = 0;
        int maxCount = 0;
        for(int i=0; i<sizeof(int)*8; i++){
            if(input>>i & 1)count++;
            else{
                maxCount = maxCount<count ? count : maxCount;
                count = 0;
            }
        }
        printf("%d\n", maxCount);
    }
}