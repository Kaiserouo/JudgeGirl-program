#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int count = 0;
int minint(int a, int b){
    return a>b?b:a;
}

int edit_distance(char *a, char *b){
    char c=*a, d=*b;
    if(c == '\0'){  count++;return strlen(b);}
    if(d == '\0'){  count++;return strlen(a);}
    if(c == d)    return edit_distance(a+1, b+1);
    else    return 1+minint(edit_distance(a+1, b), edit_distance(a, b+1));
    assert(false);
}

int main(){
    char str[150][15];
    int min_edit = 1<<14;
    int min_id1;
    int min_id2;
    printf("%d\n", count);
    int t = 0;
    while(scanf("%s", str[t]) != EOF)   t++;
    for(int i = 0; i < t; i++){
        for(int j = i+1; j < t; j++){
            int tmp = edit_distance(str[i], str[j]);
            if(min_edit > tmp){
                min_edit = tmp;
                min_id1 = i+1;
                min_id2 = j+1;
            }
        }
    }
    printf("%d %d %d, %d", min_edit, min_id1, min_id2, count);

}