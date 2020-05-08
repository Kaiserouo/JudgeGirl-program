#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 65536
#define MIN 32768

int main(){
    int32_t n;
    int16_t buf[MAXN];

    char name[201];
    scanf("%s", name);
    FILE *fp = fopen(name, "rb");

    int size;
    int count[65536] = {0}; // num+32768(MIN) -> times
    int maxTime = -1, maxElement = -50000;
    fread(&n, sizeof(int32_t), 1, fp);
    while((size = fread(buf, sizeof(int16_t), MAXN, fp)) != 0){
        for(int i = 0; i < size; i++){  // at buf[i]
            count[ buf[i]+MIN ]++;
            if(count[ buf[i]+MIN ] > maxTime || (count[ buf[i]+MIN ] == maxTime && buf[i]>maxElement)){
                maxTime = count[ buf[i]+MIN ], maxElement = buf[i];
            }
        }
    }
    printf("%d\n%d\n", maxElement, maxTime);
    
}