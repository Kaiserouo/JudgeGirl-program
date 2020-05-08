#include <stdio.h>
#include <stdlib.h>
#define MAXN 16384

typedef struct Node{
    int value;
    struct Node *left, *right;
} Node;

Node *genNode(int value, struct Node *left, struct Node *right){
    Node *tmp = malloc(sizeof(struct Node));
    *tmp = (Node){value, left, right};
    return tmp;
}
int balance(int T[], int N, int i){
    if(N == 2 || N == 1)  return 0;

    long long int torque = 0;
    for(int c = 0; c < N; c++){
        if(c == i)  continue;
        else if(c < i){
            torque -= (long long int)(T[c]*(i-c));
        }else{
            torque += (long long int)(T[c]*(c-i));
        }
    }
    return torque == 0 ? 1 : 0;
}
Node *linkedTree(int T[], int N){
    Node *last_ptr = NULL;
    Node *tmp = NULL;
    for(int i = 0; i < N; i++){
        tmp = genNode(T[i], last_ptr, NULL);
        last_ptr = tmp;
    }
    return tmp;
}

Node *ConstructTree(int T[], int N){
    int isBalanced = -1;
    for(int i = 0; i < N; i++){
        if(balance(T, N, i)) isBalanced = i;
    }
    if(isBalanced == -1){
        return linkedTree(T, N);
    }else{
        Node *tmp = genNode(T[isBalanced], NULL, NULL);
        tmp->left = ConstructTree(T, isBalanced);
        tmp->right = ConstructTree(T+isBalanced+1, N - isBalanced - 1);
        return tmp;
    }
}

/* main given */

 
int T[MAXN];
 
void PrintTree( Node *root ){
    if (root == NULL)
        return;
 
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &T[i]);
 
    Node *tree = ConstructTree( T, N );
 
    PrintTree( tree );
    return 0;
}