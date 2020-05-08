#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 65536

int main(){
    FILE *f_read = fopen("test", "rb");
    FILE *f_write = fopen("test.enc", "wb");

    int key, size;
    char buf[MAXN];
    scanf("%d", &key);
    while((size = fread(buf, 1, MAXN, f_read)) != 0){
        for(int i=0; i<size; i++){
            buf[i] ^= key;
        }
        fwrite(buf, 1, size, f_write);
    }
    fclose(f_read);
    fclose(f_write);
}