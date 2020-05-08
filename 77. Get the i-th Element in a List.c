/* node.h
#ifndef _NODE_H
#define _NODE_H
 
struct node {
       struct node *next;
};
 
#endif
*/

// for upload and debug
#define DEBUG 1
#if DEBUG == 0
#include "node.h"
#else
struct node {
       struct node *next;
};
#endif
#include <stdio.h>
#include <assert.h>
struct node *getNode(struct node *head, unsigned int i){
    unsigned int numNode = 0;
    struct node *tmp = head;
    // find numNode
    while(tmp != NULL){
        numNode++;
        tmp = tmp->next;
    }
    if(i>=numNode)   return NULL;
    else{
        tmp = head; // # numNode-1
        numNode--;
        while(numNode != i){
            numNode--;
            tmp = tmp->next;
            assert(numNode >= 0);
        }
        return tmp;
    }
}

/* test program by myself */
int main(){
    struct node n[100];
    for(int i=0; i<99; i++){
        n[i].next = n+i+1;
    }
    n[99].next = NULL;
    printf("%d", getNode(n, 100) - n);
}
