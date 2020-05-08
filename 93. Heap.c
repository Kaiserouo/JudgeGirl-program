#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
/* Heap.h
#ifndef HEAP_H
#define HEAP_H
#define MAXHEAP 100

struct Heap{
    int ary[MAXHEAP];
    int num;
};
 
void initialize(struct Heap *heap);
int removeMin(struct Heap *heap);
void add(struct Heap *heap, int i);
int isFull(struct Heap *heap);
int isEmpty(struct Heap *heap);
#endif
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#define MAXHEAP 100
 
struct Heap{
    int ary[MAXHEAP];
    int num;
};
 
 
void initialize(struct Heap *heap){
    heap->num = 0;
    return;
}
int isFull(struct Heap *heap){
    if(heap->num == MAXHEAP)return 1;
    else return 0;
}
int isEmpty(struct Heap *heap){
    if(heap->num == 0)return 1;
    else return 0;
}
int removeMin(struct Heap *heap){
    if(isEmpty(heap))return 0;
    int min = heap->ary[0], minIndex = 0;
    for(int i = 0; i < heap->num; i++){
        if(heap->ary[i] <= min)  min = heap->ary[i], minIndex = i;
    }
    heap->ary[minIndex] = heap->ary[heap->num-1];
    heap->num--;
    return min;
}
void add(struct Heap *heap, int i){
    if(isFull(heap))return;
    heap->ary[heap->num] = i;
    heap->num++;
    return;
}
int main(){
    struct Heap heap;
    initialize(&heap);
    add(&heap, 5);
    add(&heap, 3);
    add(&heap, 55);
    add(&heap, 54);
    add(&heap, 98);
    add(&heap, 2);
    while(!isEmpty(&heap)){
        printf("%d,", removeMin(&heap));
    }
}