#include "Node.h"

#ifndef Queue_h
#define Queue_h

typedef struct {
    NodePtr headPtr, tailPtr;
    int size;
} Queue;

void enqueue_struct(Queue* q, int x){
    Node *new_node = (Node*) malloc(sizeof(Node));
    if(new_node){ 
        new_node->data = x;
        new_node->nextPtr = NULL;
        
        // ถ้า size เป็น 0 หรือ head เป็น NULL คือคิวว่าง
        if(q->size == 0) 
            q->headPtr = new_node;
        else 
            q->tailPtr->nextPtr = new_node;
            
        q->tailPtr = new_node;
        q->size++;
    }
}

int dequeue_struct(Queue *q){
    NodePtr t = q->headPtr;
    
    if(t){
        int value = t->data;
        
        // 1. ขยับหัวแถว
        q->headPtr = t->nextPtr;
        
        // 2. ถ้าเหลือ 1 ตัวแล้วเอาออก (size==1) ต้องเคลียร์ tail
        if(q->size == 1)
            q->tailPtr = NULL;
            
        q->size--;
        free(t);
        
        return value;
    }
    
    printf("Empty queue\n");
    return 0;
}

#endif