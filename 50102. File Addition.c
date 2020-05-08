#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 32767
char buf1[MAXN], buf2[MAXN], bufout[MAXN];

void ensure_longer(FILE **fin1, FILE **fin2){
    fseek(*fin1, 0, SEEK_END);
    fseek(*fin2, 0, SEEK_END);
    if(ftell(*fin1) < ftell(*fin2)){
        FILE *tmp = *fin1; *fin1 = *fin2; *fin2 = tmp;
    }
}
char read_input(FILE *fin1, FILE *fin2, int buflen[3]){
    int size1 = ftell(fin1);
    int size2 = ftell(fin2);
    size1 = size1>MAXN ? MAXN:size1;  // -> size1/2 is min(ftell, MAXN)
    size2 = size2>MAXN ? MAXN:size2;
    fseek(fin1, -size1, SEEK_CUR);
    fseek(fin2, -size2, SEEK_CUR);

    buflen[1] = fread(buf1, 1, size1, fin1);
    buflen[2] = fread(buf2, 1, size2, fin2);
    buflen[0] = buflen[1];
    
    fseek(fin1, -size1, SEEK_CUR);
    fseek(fin2, -size2, SEEK_CUR);
}
int add(char c1, char c2, int carry){
    int tmp = 0;
    for(int i = 0; i < 8; i++){
        char c = (c1>>i & 1) + (c2>>i & 1) + carry;
        tmp += (c&1)<<i;
        carry = c>>1 & 1;
    }
    tmp += carry<<8;
    return tmp;
}

void simulation(FILE *fin1, FILE *fin2, FILE *fout){
    // initialization
    fseek(fin1, 0, SEEK_END);
    fseek(fin2, 0, SEEK_END);
    int len1 = ftell(fin1);
    for(int i = 0; i < len1; i++)   fputc(0, fout);

    // addition one by one
    int buflen[3] = {}; // 1,2:in, 0/1:out
    int carry = 0;
    while(1){
        // read input and record size
        read_input(fin1, fin2, buflen);
        if(!buflen[1] && !buflen[2])    break;
        // deal with input
        for(int i = 0; i < buflen[1]; i++){
            char c1 = buf1[buflen[1] - 1 - i];
            char c2 = (buflen[2] - 1 - i >= 0) ? buf2[buflen[2] - 1 - i] : 0;
            int result = add(c1, c2, carry);
            bufout[buflen[1] - 1 - i] = result & 255;
            carry = result & 256? 1: 0;
        }
        // output
        fseek(fout, -buflen[1], SEEK_CUR);
        fwrite(bufout, 1, buflen[1], fout);
        fseek(fout, -buflen[1], SEEK_CUR);
    }
}
int main(){
    char file_in[2][100], file_out[100];
    scanf("%s%s%s", file_in[0], file_in[1], file_out);

    FILE *fin1 = fopen(file_in[0], "rb");
    FILE *fin2 = fopen(file_in[1], "rb");
    FILE *fout = fopen(file_out, "wb");

    // let fin1 be the longer one
    ensure_longer(&fin1, &fin2);
    simulation(fin1, fin2, fout);

    fclose(fin1);
    fclose(fin2);
    fclose(fout);
}