#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct bstnode{
    char *str;
    struct bstnode *left;
    struct bstnode *right;
} BSTNode;

BSTNode *GenNode(char *str, int start, int word_count){
    BSTNode *new_node = malloc(sizeof(BSTNode));
    new_node->str = malloc((word_count+1) * sizeof(char));
    memcpy(new_node->str, str + start, word_count);
    new_node->str[word_count] = '\0';
    new_node->left = new_node->right = NULL;
    return new_node;
}
void InsertSubstrNode(BSTNode **root, char *str, int start, int word_count){
    if(*root == NULL){
        *root = GenNode(str, start, word_count);
        return;
    }
    
    // search pos
    BSTNode *new_node = GenNode(str, start, word_count);
    BSTNode *cur_node = *root;
    BSTNode *parent_node = NULL;
    
    int dir = 0;
    while(cur_node != NULL){
        int cmp = strcmp(new_node->str, cur_node->str);
        if(cmp == 0){
            free(new_node->str);
            free(new_node);
            return;
        }
        else if(cmp > 0){
            parent_node = cur_node;
            cur_node = cur_node->right;
            dir = cmp;
        }
        else{   // cmp < 0
            parent_node = cur_node;
            cur_node = cur_node->left;
            dir = cmp;
        }
    }
    
    if(dir > 0){    // right
        parent_node->right = new_node;
    }
    else{   //left
        parent_node->left = new_node;
    }

    return;
}
void PrintTree(BSTNode *node){
    if(node == NULL)
        return;
    PrintTree(node->left);
    printf("%s\n", node->str);
    PrintTree(node->right);
}
void GenSubstrTree(char *str, int str_len, BSTNode **root){
    for(int wi = 0; wi < str_len; wi++){
        for(int ci = 1; ci <= (str_len - wi); ci++){
            InsertSubstrNode(root, str, wi, ci);
        }
    }
}
void PrintTreeTest(BSTNode *node, int indent){
    if(node == NULL)
        return;
    PrintTreeTest(node->left, indent+1);
    for(int i = 0; i <= indent; i++){
        printf("--");
    }
    printf("%s\n", node->str);
    PrintTreeTest(node->right, indent+1);
}
void FreeTree(BSTNode *node){
    if(node == NULL)
        return;
    FreeTree(node->left);
    FreeTree(node->right);
    free(node->str);
    free(node);
}

int main(){
    char str[501];
    scanf("%s", str);
    int str_len = strlen(str);
    
    BSTNode *root = NULL;

    GenSubstrTree(str, str_len, &root);
    PrintTree(root);

    FreeTree(root);
}