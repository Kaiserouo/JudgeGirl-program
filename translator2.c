#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

// #define FUNC 0

#define NAMELEN 100
#define MAXN 65536
#define COUNT 10

enum{FILE_OUTPUT, STDOUT};
void print_binary(){
    char in[NAMELEN], out[NAMELEN];
    printf("Enter input file name:\n");
    scanf("%s", in);
    printf("Enter output file name(0: stdout):\n");
    scanf("%s", out);

    FILE *fin, *fout;
    fin = fopen(in, "rb");
    assert(fin != NULL);
    if(!strcmp("0", out)){
        fout = stdout;
    }else{
        fout = fopen(out, "w");
        assert(fout != NULL);
    }

    char buf[MAXN];
    int size, count = 0;
    while((size = fread(buf, 1, MAXN, fin)) != 0){
        for(int i=0; i<size; i++){
            for(int j=7; j>=0; j--){
                fprintf(fout, "%d", buf[i] & 1<<j ? 1 : 0);
            }
            fputc(' ', fout);
            count++;
            if(count == COUNT){
                count = 0, fputc('\n', fout);
            }
        }
    }

    fclose(fin);
    if(fout != stdout)fclose(fout);
    printf("\nExit successful\n");
}
void write_binary(){
    char out[NAMELEN];
    printf("Enter output file name:\n");
    scanf("%s", out);

    FILE *fout;
    fout = fopen(out, "wb");
    assert(fout != NULL);

    char buf[MAXN];
    int size, count = 0;
    char c = 0;
    while(scanf("%s", buf) != EOF){
        size = strlen(buf);
        for(int i=0; i<size; i++){
            c += (buf[i]-'0')<<(7-count);
            count++;
            if(count == 8){
                fputc(c, fout);
                c = 0;
                count = 0;
            }
        }
    }

    fclose(fout);
}
int main(){
    int mode;
    while(1){
        printf("Mode(1: print, 2: write, 3:exit): ");
        scanf("%d", &mode);
        switch(mode){
            case 1: print_binary(); break;
            case 2: write_binary(); break;
            case 3: exit(0);
        }
    }
}
