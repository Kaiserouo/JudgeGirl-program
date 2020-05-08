#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int numNode, numCmp;
int *nodeData;
int *nodeLevel;
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

// find max level of all nodeLevel
int find_maxLevel(){
    int max = 0;
    for(int i = 0; i < numNode; i++){
        max = max > nodeLevel[i] ? max : nodeLevel[i];
    }
    return max;
}

BinaryTree *BST_insert(BinaryTree *head, int data){
    if(head == NULL){
        return genNode(data, NULL, NULL);
    }
    else if(head->data > data){  // put left
        if(head->left == NULL){
            head->left = genNode(data, NULL, NULL);
            return head;
        }
        else{
            head->left = BST_insert(head->left, data);
            return head;
        }
    }else{
        if(head->right == NULL){
            head->right = genNode(data, NULL, NULL);
            return head;
        }
        else{
            head->right = BST_insert(head->right, data);
            return head;
        }
    }
}
// make BST by data inputted. return head
BinaryTree *initialize(){
    int max_level = find_maxLevel();
    BinaryTree *head = NULL;
    for(int i = 1; i <= max_level; i++){
        for(int j = 0; j < numNode; j++){
            if(nodeLevel[j] == i)   head = BST_insert(head, nodeData[j]);
        }
    }
    return head;
}

// given head and data, add node to binary search tree

// inorder traversal output to test. Rotate output -90 degrees to get tree
int inorder_traversal(BinaryTree *head, int indent){
    if(head == NULL){
        for(int i = 0; i < indent; i++) printf("   ");printf("NULL\n");
        return 0;
    }else{
        inorder_traversal(head->right, indent+1);
        for(int i = 0; i < indent; i++) printf("   ");
        printf("%d\n", head->data);
        inorder_traversal(head->left, indent+1);
    }
    return 0;
}

// guarentee in this tree, find distance
int existNode(BinaryTree *head, int data){
    if(head->data == data)  return 0;
    else if(head->data < data)  return existNode(head->right, data)+1;
    else if(head->data > data)  return existNode(head->left, data)+1;
    else assert(false);
}

// return 2 nodes' distance given their data. if not in same tree return 0
int node_distance(BinaryTree *head, const int *dist){
    if(head->data < dist[0] && head->data < dist[1])    return node_distance(head->right, dist);
    else if(head->data > dist[0] && head->data > dist[1])    return node_distance(head->left, dist);
    else if(head->data == dist[0])  return existNode(head, dist[1]);
    else if(head->data == dist[1])  return existNode(head, dist[0]);
    else return existNode(head, dist[0]) + existNode(head, dist[1]);
}

int main(){
    scanf("%d", &numNode);
    nodeData = malloc(numNode * sizeof(int));
    nodeLevel = malloc(numNode * sizeof(int));
    for(int i = 0; i < numNode; i++){
        scanf("%d%d", &nodeData[i], &nodeLevel[i]);
    }
    BinaryTree *head = initialize();
    scanf("%d", &numCmp);

    int cmp[2];
    for(int i = 0; i < numCmp; i++){
        scanf("%d%d", &cmp[0], &cmp[1]);
        printf("%d\n", node_distance(head, cmp));
    }
}