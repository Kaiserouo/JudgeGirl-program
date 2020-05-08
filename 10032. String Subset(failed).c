#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

//n
char *GenerateSubstr(char *str, int start, int word_count){
    char *new_str = malloc((word_count+1) * sizeof(char));
    memcpy(new_str, str + start, word_count);
    new_str[word_count] = '\0';
    return new_str;
}

//n**2
char *SearchStr(char *target, char **str_set, int str_n){
    for(int si = 0; si < str_n; si++){
        if(!strcmp(target, str_set[si]))
            return str_set[si];
    }
    return NULL;
}

void GenerateSubstrSet(char *str, int str_len, char **substr_set, int *substr_n){
    for(int si = 0; si < str_len; si++){
        for(int wi = 1; wi <= (str_len - si); wi++){
            char *new_str = GenerateSubstr(str, si, wi);
            if (!SearchStr(new_str, substr_set, *substr_n)){
                substr_set[*substr_n] = new_str;
                (*substr_n)++;
            }
        }
    }
    return;
}

void FreeSubstrSet(char **substr_set, int substr_n){
    for(int si = 0; si < substr_n; si++){
        free(substr_set[si]);
    }
    return;
}

void PrintSet(char **substr_set, int substr_n){
    for(int si = 0; si < substr_n; si++){
        printf("%s\n", substr_set[si]);
    }
}

//n
int Compare(const void *a, const void *b){
    char **ptr1 = (char **)a;
    char **ptr2 = (char **)b;
    return strcmp(*ptr1, *ptr2);
}

int main(){
    char str[501];
    scanf("%s", str);
    int str_len = strlen(str);
    
    char *substr_set[str_len * (str_len + 1) / 2];  // maximum #sub string
    int substr_n = 0;

    GenerateSubstrSet(str, str_len, substr_set, &substr_n);
    qsort(substr_set, substr_n, sizeof(char *), Compare);
    PrintSet(substr_set, substr_n);

    FreeSubstrSet(substr_set, substr_n);
}