#include <stdio.h>
#include <stdlib.h>

#define MAXN 128
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *genNode(int data, Node *left, Node *right){
    Node *tmp = malloc(sizeof(Node));
    *tmp = (Node){data, left, right};
    return tmp;
}
Node *construct(Node *root, char instruction[MAXN]){
    int i = 0;
    Node *tmp;
    if(root == NULL)    tmp = genNode(0, NULL, NULL), root = tmp;
    else    tmp = root;
    Node *cur = root;
    Node *prev = NULL;
    cur->data++;
    while(instruction[i] != '\0'){
        switch (instruction[i]){
        case 'L':
            prev = cur;
            cur = cur->left;
            if(cur == NULL) {
                cur = genNode(0, NULL, NULL); 
                prev->left = cur;
            }
            break;
        case 'R':
            prev = cur;
            cur = cur->right;
            if(cur == NULL) {
                cur = genNode(0, NULL, NULL); 
                prev->right = cur;
            }
            break;
        }
        if(cur == NULL) {
            cur = genNode(0, NULL, NULL);
            
        }
        cur->data++;
        i++;
    }
    return tmp;
}
int query(Node *root, char instruction[MAXN]){
    int i = 0;
    Node *cur = root;
    while(instruction[i] != '\0'){
        switch (instruction[i]){
        case 'L':
            cur = cur->left;
            break;
        case 'R':
            cur = cur->right;
            break;
        }
        if(cur == NULL) return 0;
        i++;
    }
    return cur->data;
}

/* given main */
#ifdef TEST_CONSTRUCT
void preorder(Node *root) {
    if (root == NULL)
        return ;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root) {
    if (root == NULL)
        return ;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    char instruction[MAXN];
    Node *root = NULL;
    while (scanf("%s", instruction) != EOF) {
        root = construct(root, instruction);
        preorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
    }
    return 0;
}
#else
#ifdef TEST_QUERY
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main()
{
    char instruction[MAXN];
    Node node[7];
    for(int i = 0; i < 7; i++){
        node[i].left = NULL;
        node[i].right = NULL;
    }
    node[0].data = 2;
    node[0].left = &node[1];
    node[1].data = 2;
    node[1].right = &node[2];
    node[2].data = 2;
    node[2].left = &node[3];
    node[2].right = &node[4];
    node[3].data = 1;
    node[3].left = &node[5];
    node[4].data = 1;
    node[4].right = &node[6];
    node[5].data = 1;
    node[6].data = 1;
    Node *root = &node[0];
    while (scanf("%s", instruction) != EOF) {
        printf("%d\n", query(root, instruction));
    }
    return 0;
}
#endif
#endif