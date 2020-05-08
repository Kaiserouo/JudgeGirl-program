#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

/* define & variable */
#define MAXLEN 1024
char var[100][100];
int value[100], numVar = 0;

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
    if(isdigit(c[0])){  // digit
        for(int i=0; isdigit(c[i]); i++){
            sum = sum*10 + (c[i] - '0');
        }
        return sum;
    }
    else{   // variable
        char tmp[100] = {0};
        int i;
        for(i=0; c[i] != ' '; i++){
            tmp[i] = c[i];
        }tmp[i] == '\0';
        // search
        for(int j = 0; j < numVar; j++){
            if(!strcmp(var[j], tmp)){
                return value[j];
            }
        }
        assert(false);
    }
}

// make expression tree
BinaryTree *makeExpTree(char *c){
    static char *rightparenth = 0;
    if(c[0] != '('){    // number
        rightparenth = strchr(c, ' ')-1;
        return genNode(parseInt(c), NULL, NULL);
    }
    else{   // tree
        assert(isspace(c[1]) && isspace(c[3]));
        int operator = c[2];
        BinaryTree *node1 = makeExpTree(c+4);
        assert(isspace(rightparenth[1]));
        BinaryTree *node2 = makeExpTree(rightparenth+2);
        assert(isspace(rightparenth[1]) && rightparenth[2] == ')');
        rightparenth += 2;
        return genNode(operator, node1, node2);
    }

}

// inorder traversal output to test. Rotate output -90 degrees to get tree
int inorder_traversal(BinaryTree *head, int indent){
    if(head->left == NULL && head->right == NULL){
        for(int i = 0; i < indent; i++) printf("    ");printf("%d\n", head->data);
        return 0;
    }else{
        inorder_traversal(head->right, indent+1);
        for(int i = 0; i < indent; i++) printf("    ");
        printf("%c\n", head->data);
        inorder_traversal(head->left, indent+1);
    }
    return 0;
}

// evaluate everything
int evaluate(BinaryTree *head){
    if(head->left == NULL && head->right == NULL){  // leaf
        return head->data;
    }
    else{   // opreator
        switch(head->data){
        case '+':
            return evaluate(head->left) + evaluate(head->right);
        case '-':
            return evaluate(head->left) - evaluate(head->right);
        case '*':
            return evaluate(head->left) * evaluate(head->right);
        case '/':
            return evaluate(head->left) / evaluate(head->right);
        default:
            assert(false);
        }
    }
}

/* main */
int main(){
    char str[MAXLEN], input;

    // input
    int num = 0;
    while(input != '\n'){
        str[num++] = input = getchar();
    }str[num] = '\0';

    while(scanf("%s = %d", var[numVar], &value[numVar]) != EOF){
        numVar++;
    }
    BinaryTree *head = makeExpTree(str);
    printf("%d", evaluate(head));
}