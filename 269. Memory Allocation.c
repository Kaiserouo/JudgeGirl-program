/* header file:
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct mem{
    int startPos;
    int size;
    struct mem *next;
} Memory;
void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);
*/

/*** HAVEN'T ACTUALLY FINISHED YET : TEST DIDN'T PASS FOR UNKNOWN REASONS ***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct mem{
    int startPos;
    int size;
    struct mem *next;
} Memory;

Memory *genNode(int startPos, int size, Memory *next){
    Memory *tmp = malloc(sizeof(Memory));
    *tmp = (Memory){startPos, size, next};
    return tmp;
}

// initialize memory, note that if allocate 100, then index [0~99] is avaliable
void initMemory(Memory *memory, int length){
    *memory = (Memory){0, length, NULL};
}
// print memory according to format. All start & length hassle should
// be dealt with in allocate & free memory function.
void printMemory(Memory *memory){
    printf("==========\n");
    // if empty
    if(memory->size == 0 && memory->startPos == 0)  return;
    Memory *m = memory;
    while(m != NULL){
        printf("start %d, length %d\n", m->startPos, m->size);
        m = m->next;
    }
}

void allocateMemory(Memory *memory, int start, int length){
    Memory *prev = NULL;
    Memory *cur = memory;
    
    while((cur != NULL) && !(start >= cur->startPos && start+length <= cur->size + cur->startPos)){
        prev = cur;
        cur = cur->next;
    }
    if(cur == NULL)  assert(false); // can't find block to allocate
    // case: allocate whole block
    else if(start==cur->startPos && start+length==cur->size+cur->startPos){
        // if first
        if(prev == NULL){
            if(cur->next != NULL){
                *cur = (Memory){cur->next->startPos, cur->next->size, cur->next->next};
                free(cur->next);
            }
            // if going to be empty (only one in list)
            else{
                *memory = (Memory){0, 0, NULL};
            }
        }
        // if any other block, including last
        else{
            prev->next = cur->next;
            free(cur);
        }
    }
    // case: head match
    else if(start == cur->startPos){
        cur->startPos += length;
        cur->size -= length;
    }
    // case: tail match
    else if(start+length == cur->size+cur->startPos){
        cur->size -= length;
    }
    // default: seperate into 2 blocks
    else{
        Memory *tmp = genNode(start+length, cur->size - length - start + cur->startPos, cur->next);
        cur->next = tmp;
        cur->size = start - cur->startPos;
    }
}
void freeMemory(Memory *memory, int start, int length){
    assert(memory != NULL);
    Memory *cur = memory->next;
    Memory *prev = memory;
    if(memory->size == 0 && memory->startPos == 0){
        memory->size = length;
        memory->startPos = start;
        return;
    }
    // at start
    if(start+length <= memory->startPos){
        if(start+length == memory->startPos){
            memory->startPos = start;
            memory->size += length;
        }
        if(start+length < memory->startPos){
            Memory *tmp = genNode(memory->startPos, memory->size, memory->next);
            *memory = (Memory){start, length, tmp};
        }
        return;
    }
    while(cur != NULL && !(start>=prev->startPos+prev->size && start+length<=cur->startPos)){
        // haven't dealt with exceptions
        prev = cur;
        cur = cur->next;
    }

    // at end
    if(cur == NULL){
        // can connect last block
        if(prev->startPos + prev->size == start){
            prev->size += length;
        }
        // can't connect last block
        else{
            prev->next = genNode(start, length, NULL);
        }
    }
    // at middle
    else{
        // connect to both cur and prev
        if(start == prev->startPos+prev->size && start+length == cur->startPos){
            prev->size += length + cur->size;
            prev->next = cur->next;
            free(cur);
        }
        // only to prev
        else if(start == prev->startPos+prev->size){
            prev->size += length;
        }
        // only to cur
        else if(start+length == cur->startPos){
            cur->startPos = start;
            cur->size += length;
        }
        // default: create new block
        else{
            prev->next = genNode(start, length, cur);
        }
    }
}

/* main */
int main() {
    Memory m;
    char ch;
    int a,b,c;
    int counter = 0;
    while(scanf("%c", &ch) != EOF){
        counter++;
        switch(ch){
        case 'I' :
            scanf("%d%d", &a, &b);
            initMemory(&m, b);
            
            break;
        case 'A' :
            scanf("%d%d%d", &a, &b, &c);
            allocateMemory(&m, b, c);
            
            break;
        case 'P' :
            scanf("%d", &a);
            printMemory(&m);
            break;
        case 'F' :
            scanf("%d%d%d", &a, &b, &c);
            freeMemory(&m, b, c);
            
            break;
        }
    }
}