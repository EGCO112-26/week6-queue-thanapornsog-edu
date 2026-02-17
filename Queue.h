#ifndef Queue_h
#define Queue_h
#include "Node.h"
#include <stdlib.h>

typedef struct Queue {
    order *head, *tail;
    int size;
} Queue;

void enqueue_struct(Queue* q, int order_number, int qty) {
    order* new_node = (order*)malloc(sizeof(order));
    if (new_node) {
        new_node->order_number = order_number;
        new_node->q = qty;
        new_node->next = NULL;
        
        if (q->size == 0) {
            q->head = new_node;
        } else {
            q->tail->next = new_node;
        }
        
        q->tail = new_node;
        q->size++;
    }
}

int dequeue_struct(Queue *q, int *order_number, int *qty) {
    if (q->size == 0) {
        return 0;
    }
    
    order* t = q->head;
    *order_number = t->order_number;
    *qty = t->q;
    
    q->head = t->next;
    
    if (q->size == 1) {
        q->tail = NULL;
    }
    
    q->size--;
    free(t);
    return 1;
}

#endif
    
    q->headPtr = t->nextPtr;
    
    if (q->size == 1) {
        q->tailPtr = NULL;
    }
    
    q->size--;
    free(t);
    return 1;
}

#endif
    
    q->headPtr = t->nextPtr;
    
    if (q->size == 1) {
        q->tailPtr = NULL;
    }
    
    q->size--;
    free(t);
    return 1;
}

#endif
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
