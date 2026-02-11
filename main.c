#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc, char **argv) {
    Queue q;
    q.headPtr = NULL;
    q.tailPtr = NULL;
    q.size = 0;

    int i, x;

    for(i = 1; i < argc; i++){
        if(strcmp(argv[i], "x") == 0){
           
            x = dequeue_struct(&q);
            if(x != 0) {
                printf("Dequeing %d\n", x);
            }
        }
        else {
            x = atoi(argv[i]);
            enqueue_struct(&q, x);
            printf("Enqueing %d\n", x);
        }
    }
    return 0;
}