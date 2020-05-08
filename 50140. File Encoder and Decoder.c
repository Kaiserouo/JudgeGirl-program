#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
void bin2ascii(char input_file[32], char output_file[32], char dict[17]){
    FILE *fin = fopen(input_file, "rb");
    assert(fin != NULL);
    FILE *fout = fopen(output_file, "w");
    assert(fout != NULL);
    
    int size;
    char buf;
    while(fread(&buf, 1, 1, fin) != 0){
            fprintf(fout, "%c%c", dict[buf>>4 & 15], dict[buf & 15]);
    }
}
char hash(char c, char dict[17]){
    for(char i = 0; i < 17; i++){
        if(c == dict[i])
        {printf("%d\n", i);return i;}
    }
}
void ascii2bin(char input_file[32], char output_file[32], char dict[17]){
    FILE *fin = fopen(input_file, "r");
    assert(fin != NULL);
    FILE *fout = fopen(output_file, "wb");
    assert(fout != NULL);
    
    char in[2];
    while(fscanf(fin, "%c%c", &in[0], &in[1]) != EOF){
        char c = 0;
        c += (hash(in[0], dict))<<4;
        c += (hash(in[1], dict));
        
        printf("    %d\n", c);
        fwrite(&c, 1, 1, fout);
    }
}

/* given main */
int main(){
    int T;
    char input_file[32];
    char output_file[32];
    char dict[17];
    scanf("%d%s%s%s", &T, input_file, output_file, dict);
    if(T)ascii2bin(input_file, output_file, dict);
    else bin2ascii(input_file, output_file, dict);
    return 0;
}