#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char c;
    struct Node *next;
}Node;
int check_substr(Node *text, Node *pattern, int i){
    int sum = 0;
    while(pattern != NULL && text != NULL){
        if(pattern->c == text->c)   sum += i++, text = text->next, pattern = pattern->next;
        else return 0;
    }
    if(pattern != NULL) return 0;
    return sum;
}
void substring(Node* text, Node* pattern){
    int i = 0;
    int num = 0;
    while(text != NULL){
        while(text != NULL && text->c != pattern->c) text = text->next, i++;
        if(text == NULL) break;
        if(num = check_substr(text, pattern, i)){
            printf("%d\n", num);
            return;
        }
        text = text->next, i++;
    }
    printf("0\n");
    return;
}
void subsequence(Node* text, Node* pattern){
    int i = 0;
    int num = 0;
    while(text != NULL && pattern != NULL){
        while(text != NULL && text->c != pattern->c) text = text->next, i++;
        if(text == NULL) break;
        num += i;
        pattern = pattern->next;
        text = text->next, i++;
    }
    printf("%d\n", num);
    return;
}

/* main given */
#ifdef TM
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
Node* insert(Node* root, char c)
{
    if(root == NULL){
        root = (Node*)malloc(sizeof(Node));
        root->c = c;
        root->next = NULL;
        return root;
    }
    root->next = insert(root->next, c);
    return root;
}
int main(int argc, char const *argv[])
{
    char tmp = '\n';
    int N, M, i, act;
    Node *text = NULL, *pattern = NULL, *cur = NULL;
 
    scanf("%d%d", &act, &N);
    while(isspace(tmp)) scanf("%c", &tmp);
    text = insert(text, tmp);
    cur = text;
    for(i = 0; i < N-1; i++){
        scanf("%c", &tmp);
        cur->next = insert(cur->next, tmp);
        cur = cur->next;
    }
 
    scanf("%d", &M);
    tmp = '\n';
    while(isspace(tmp)) scanf("%c", &tmp);
    pattern = insert(pattern, tmp);
    cur = pattern;
    for(i = 0; i < M-1; i++){
        scanf("%c", &tmp);
        cur->next = insert(cur->next, tmp);
        cur = cur->next;
    }
    if (!act)
        substring(text, pattern);
    else
        subsequence(text, pattern);
    return 0;
}
#endif

