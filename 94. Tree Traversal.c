#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

/* structure */
typedef struct binarytree{
    int data;
    struct binarytree *left;
    struct binarytree *right;
} BinaryTree;
/* function */
// generate tree with initialization parameter and return pointer of new node
BinaryTree *genNode(int data, BinaryTree *left, BinaryTree *right){
    BinaryTree *tmp = malloc(sizeof(BinaryTree));
    *tmp = (BinaryTree){data, left, right};
    return tmp;
}

// read string and return int when reach NULL or not digit
int parseInt(char *c){
    int sum = 0;
    for(int i=0; isdigit(c[i]); i++){
        sum = sum*10 + (c[i] - '0');
    }
    return sum;
}

// make Binarytree by input ( ()/num , ()/num ) to make tree.
// return head
BinaryTree *initialize(char *c){
    static char *rightparenth = 0;  // pointer to next parenthesis
    char *nextTree = NULL;  // a pointer to second tree in this parenthesis
    assert(c[0] == '(');
    BinaryTree *node1, *node2;
    if(c[1] == '('){    // node1 is tree
        node1 = initialize(c+1);
        nextTree = rightparenth+1;
    }else if(isdigit(c[1])){  // node1 is num
        node1 = genNode(parseInt(c+1), NULL, NULL);
        nextTree = strchr(c, ',');
    }else{
        assert(false);
    }

    assert(*nextTree == ',');
    
    if(nextTree[1] == '('){    // node1 is tree
        node2 = initialize(nextTree+1);
        rightparenth++; // this parenthesis' right
    }else if(isdigit(nextTree[1])){  // node2 is num
        node2 = genNode(parseInt(nextTree+1), NULL, NULL);
        rightparenth = strchr(nextTree, ')');
    }else{
        assert(false);
    }
    
    return genNode(node1->data + node2->data, node1, node2);
}

// traverse using HLHR order, p: 1,HLHR;other,HRHL
int traversal(BinaryTree *head, int p){
    if(head == NULL)    return 0;
    printf("%d\n", head->data);
    if(p == 1) traversal(head->left, 0);
    else traversal(head->right, 1);
    printf("%d\n", head->data);
    if(p == 1) traversal(head->right, 0);
    else traversal(head->left, 1);
}

// inorder traversal output to test. Rotate output -90 degrees to get tree
int inorder_traversal(BinaryTree *head, int indent){
    if(head == NULL){
        for(int i = 0; i < indent; i++) printf("  ");printf("NULL\n");
        return 0;
    }else{
        inorder_traversal(head->right, indent+1);
        for(int i = 0; i < indent; i++) printf("  ");
        printf("%d\n", head->data);
        inorder_traversal(head->left, indent+1);
    }
    return 0;
}

// free pointer of Binarytree
void freeTree(BinaryTree *head){
    if(head == NULL)    return;
    freeTree(head->left);
    freeTree(head->right);
    free(head);
}

/* main */
int main(){
    char input[10000];
    scanf("%s", input);
    BinaryTree *head = initialize(input);
    traversal(head, 1);
    freeTree(head);
}