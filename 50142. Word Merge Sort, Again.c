#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
void read_input(char input[][4], int num_file, int index, char hasEOF[], FILE *fin[]){
    if(index == -1){
        for(int i = 0; i < num_file; i++){
            if(hasEOF[i])   continue;
            int count = fread(input[i], 3, sizeof(char), fin[i]);
            input[i][3] = '\0';
            if(count == 0)  hasEOF[i] = 1;
        }
    }
    else{
        if(hasEOF[index])   return;
        int count = fread(input[index], 3, sizeof(char), fin[index]);
        input[index][3] = '\0';
        if(count == 0)  hasEOF[index] = 1;
    }
}
void merge_file(FILE *fin[], int num_file, FILE *fout){
    char hasEOF[num_file];
    memset(hasEOF, 0, sizeof(char)*num_file);
    char input[num_file][4];
    read_input(input, num_file, -1, hasEOF, fin);
    while(1){
        // find max
        int max_index = -2;
        for(int i = 0; i < num_file; i++){
            if(hasEOF[i])   continue;
            else if(max_index == -2) {
                max_index = i;
            }
            else if(strcmp(input[max_index], input[i]) > 0)  {
                max_index = i;
            }
        }
        fprintf(fout, "%s", input[max_index]);
        read_input(input, num_file, max_index, hasEOF, fin);
        int flag = 0;
        for(int i = 0; i < num_file; i++){
            if(!hasEOF[i])  flag = 1;    
        }
        if(!flag) break;
        
    }
}

int main(){
    int num_file;
    scanf("%d", &num_file);
    FILE *fin[num_file];
    for(int i = 0; i < num_file; i++){
        char tmp[100];
        scanf("%s", tmp);
        fin[i] = fopen(tmp, "r");
        assert(fin[i] != NULL);
    }
    char tmp[100];
    scanf("%s", tmp);
    FILE *fout = fopen(tmp, "w");
    assert(fout != NULL);
    merge_file(fin, num_file, fout);
    for(int i = 0; i < num_file; i++){
        fclose(fin[i]);
    }
    fclose(fout);
}