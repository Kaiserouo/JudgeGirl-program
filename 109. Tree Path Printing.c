/*  Node.h
#ifndef _NODE_H
#define _NODE_H
 
struct node {
    struct node *left;
    struct node *right;
    int data;
};
 
void print_all_paths(struct node *root);
 
#endif
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
    struct node *left;
    struct node *right;
    int data;
};
// inorder traversal output to test. Rotate output -90 degrees to get tree
int inorder_traversal(struct node *head, int indent){
    if(head == NULL){
        for(int i = 0; i < indent; i++) printf("     ");printf("NULL\n");
        return 0;
    }else{
        inorder_traversal(head->right, indent+1);
        for(int i = 0; i < indent; i++) printf("     ");
        printf("%d\n", head->data);
        inorder_traversal(head->left, indent+1);
    }
    return 0;
}

void print_all_paths(struct node *root){
    static int output[1005] = {0};
    static int outNum = 0;
    static int hasPrinted = 0;  // in case program print twice

    if(root == NULL){   // terminal
        if(hasPrinted)  return;
        else{   // print
            for(int i = 0; i < outNum; i++){
                printf("%d%s", output[i], i==outNum-1 ? "\n":" ");
            }
            hasPrinted = 1;
        }
    }
    else{
        hasPrinted = 0;
        output[outNum++] = root->data;
        // if have path, dont walk NULL to avoid unnecessary output
        if(root->left != NULL && root->right != NULL){
            int curOutNum = outNum; // temporarily storing current depth
            print_all_paths(root->left);
            outNum = curOutNum;
            print_all_paths(root->right);
        }
        else if(root->left == NULL && root->right != NULL){
            print_all_paths(root->right);
        }
        else if(root->left != NULL && root->right == NULL){
            print_all_paths(root->left);
        }
        else{
            print_all_paths(root->left);    // whatever, just walk
        }
    }
}
 
/* program given */ 
struct node *insert_bs_tree(struct node *root, int data)
{
    struct node *current;
    if (root == NULL)
    {
        current = (struct node *)malloc(sizeof(struct node));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if (data < root->data)
        root->left = insert_bs_tree(root->left, data);
    else
        root->right = insert_bs_tree(root->right, data);
    return root;
}
 
int main(void)
{
    int n;
    struct node *root = NULL;
 
    while (scanf("%d", &n) != EOF)
        root = insert_bs_tree(root, n);
    inorder_traversal(root, 0);
    print_all_paths(root);
}
