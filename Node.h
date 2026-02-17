#ifndef Node_h
#define Node_h

typedef struct node {
    int order_number;
    int q;
    struct node* nextPtr;
} OrderNode;

typedef OrderNode* NodePtr;

#endif
int dequeue(NodePtr* head, NodePtr* tail){
  NodePtr t=*head;
   if(t){
   int value= t->data;
   *head=t->nextPtr;
   if(*head==NULL) *tail=NULL;
      free(t);
      return value;
       
       
   return value;
   }
   printf("Empty queue");
   return 0;
}



#endif
