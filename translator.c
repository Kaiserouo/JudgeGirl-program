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

#ifdef FUNC

// read a binary file and output byte by byte with
// space every 8 bit. Use mode to determine output:
// 0: file output
// 1: standard output(didn't use file_out argument)
int binary_translator(int mode, char *file_in, char *file_out){
    FILE *fin, *fout;
    fin = fopen(file_in, "rb");
    assert(fin != NULL);
    if(mode == FILE_OUTPUT){
        fout = fopen(file_out, "w");
        assert(fout != NULL);
    }
    else if(mode == STDOUT){
        fout = stdout;
    }
    else assert(false);

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
    if(mode == FILE_OUTPUT)fclose(fout);
}

#else

int main(){
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
}

#endif