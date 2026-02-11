typedef struct {
    NodePtr headPtr, tailPtr;
    int size;
} Queue;

void enqueue_struct(Queue* q, int x){
    Node *new_node = (Node*) malloc(sizeof(Node));
    if(new_node){ 
        new_node->data = x;
        new_node->nextPtr = NULL;
        
        /* Finish enqueue */
        if(q->size == 0) 
            q->headPtr = new_node;
        else 
            q->tailPtr->nextPtr = new_node;
            
        q->tailPtr = new_node;
        q->size++;
    }
} // <--- เดิมคุณลืมปิดวงเล็บปีกกาตรงนี้

int dequeue_struct(Queue *q){
    NodePtr t = q->headPtr;
    if(t){
        int value = t->data;
        
        /* Finish dequeue */
        q->headPtr = q->headPtr->nextPtr; // ขยับหัวแถว
        
        // แก้ไขจุดที่ผิด: ถ้าเดิมมี 1 ตัว (size==1) เอาออกแล้วต้องเซ็ต tail เป็น NULL
        if(q->size == 1) 
            q->tailPtr = NULL; 
            
        q->size--;
        free(t);
        
        return value;
    }
    
    printf("Empty queue\n");
    return 0;
}