#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int main(){
    char words[200][55];
    int num_word, num_query;
    scanf("%d", &num_word);
    for(int wi = 0; wi < num_word; wi++){
        scanf("%s", words[wi]);
    }

    scanf("%d", &num_query);
    for(int qi = 0; qi < num_query; qi++){
        char subs[55];
        int counter = 0;
        scanf("%s", subs);
        for(int wi = 0; wi < num_word; wi++){
            if(strstr(words[wi], subs) != NULL)
                counter++;
        }
        printf("%d\n", counter);
    }
}