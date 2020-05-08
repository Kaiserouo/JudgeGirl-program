#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 100000

void sub_string(char *alpha_list, int n){
    for(int i = 0; i < n; i++){
        char new_c, old_c;
        scanf("\n%c %c", &new_c, &old_c);
        for(int ai = 0; ai < 26; ai++){
            if(alpha_list[ai] == old_c)
                alpha_list[ai] = new_c;
        }
    }
    return;
}

int main(){
    char str[MAXN];
    int num_sub;
    scanf("%s", str);
    scanf("%d", &num_sub);
    
    char alpha_list[26];
    for(int i = 0; i < 26; i++){
        alpha_list[i] = 'A' + i;
    }
    
    sub_string(alpha_list, num_sub);

    for(int i = 0, len = strlen(str); i < len; i++){
        putchar(alpha_list[ str[i] - 'A' ]);
    }
    putchar('\n');
}