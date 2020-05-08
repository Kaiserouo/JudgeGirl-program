#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}Node;

int all_null(Node *list[], int K){
    for(int i = 0; i < K; i++){
        if(list[i] != NULL)return 0;
    }
    return 1;
}
void to_next(Node *list[], int K){
    for(int i = 0; i < K; i++){
        if(list[i] != NULL)   list[i] = list[i]->next;
    }
    return;
}
Node *merge(Node *list[], int K){
    Node *next[K];
    Node *cur[K];
    Node *last = NULL;
    Node *ret = NULL;
    memcpy(cur, list, K*sizeof(Node *));
    memcpy(next, list, K*sizeof(Node *));
    #ifdef ZIGZAG
    int is_down = 1;
    #else
    #ifdef TOPDOWN
    int is_down = 1;
    #else
    #ifdef BOTTOMUP
    int is_down = -1;
    #endif
    #endif
    #endif
    while(1){
        to_next(next, K);
        for(int i = 0; i < K; i++){
            int index = is_down == 1 ? i : K-1-i;

            if(cur[index] == NULL)  continue;
            else if(last == NULL){
                last = cur[index];
                ret = cur[index];
            }
            else{
                last->next = cur[index];
                last = cur[index];
            }
        }
        memcpy(cur, next, K*sizeof(Node *));
        #ifdef ZIGZAG
        is_down *= -1;
        #endif
        if(all_null(cur, K))   break;
    }
    last->next = NULL;
    return ret;
}

/* given main */
#ifdef TM
#include <stdio.h>
#include <stdlib.h>
 
int main () {
        int K;
        scanf("%d", &K);
        Node *list[K];
        for (int i = 0; i < K; i++) {
                int N;
                scanf("%d", &N);
                if (N == 0) {
                        list[i] = NULL;
                        continue;
                }
                list[i] = (Node *)malloc(sizeof(Node));
                scanf("%d", &(list[i]->data));
                list[i]->next = NULL;
                Node *previous = list[i];
                for (int j = 1; j < N; j++) {
                        previous->next = (Node *)malloc(sizeof(Node));
                        scanf("%d", &(previous->next->data));
                        previous->next->next = NULL;
                        previous = previous->next;
                }
        }
        Node *result = merge(list, K);
        while (result) {
                printf("%d", result->data);
                result = result->next;
                printf("%c", result ? ' ' : '\n');
        };
        return 0;
}
#endif