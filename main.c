#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc, char **argv) {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    int i;
    int customer_no = 1;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "x") == 0) {
            int order_num, qty;
            
            if (dequeue_struct(&q, &order_num, &qty)) {
                printf("Customer no: %d\n", customer_no++);
                
                int price = 0;
                if (order_num == 1) {
                    printf("Zinger Burger\n");
                    price = 89 * qty;
                } else if (order_num == 2) {
                    printf("Fried Chicken\n"); 
                    price = 45 * qty;
                } else if (order_num == 3) {
                    printf("French Fries\n");
                    price = 55 * qty;
                } else {
                    printf("Unknown item\n");
                    price = 0;
                }

                printf("You have to pay %d\n", price);
                
                int cash = 0;
                printf(":Cash:");
                scanf("%d", &cash);
                
                while (cash < price) {
                    printf("Cash:");
                    scanf("%d", &cash);
                }
                
                printf("Thank you\n");
                
                if (cash > price) {
                    printf("Change is:%d\n", cash - price);
                }
                
            } else {
                printf("Empty queue\n");
            }
        } else {
            if (i + 1 < argc) {
                int order_num = atoi(argv[i]);
                int qty = atoi(argv[i+1]);
                
                printf("My order is %d\n", order_num);
                enqueue_struct(&q, order_num, qty);
                
                i++; 
            }
        }
    }

    printf("=========================================\n");
    printf("There are %d ppl left in the queue\n", q.size);

    int temp_order, temp_qty;
    while (q.size > 0) {
        dequeue_struct(&q, &temp_order, &temp_qty);
    }

    return 0;
}

                printf("You have to pay %d\n", price);
                
                int cash = 0;
                printf(":Cash:");
                scanf("%d", &cash);
                
                while (cash < price) {
                    printf("Cash:");
                    scanf("%d", &cash);
                }
                
                printf("Thank you\n");
                
                if (cash > price) {
                    printf("Change is:%d\n", cash - price);
                }
                
            } else {
                printf("Empty queue\n");
            }
        } else {
            if (i + 1 < argc) {
                int order_num = atoi(argv[i]);
                int qty = atoi(argv[i+1]);
                
                printf("My order is %d\n", order_num);
                enqueue_struct(&q, order_num, qty);
                
                i++; 
            }
        }
    }

    printf("=========================================\n");
    printf("There are %d ppl left in the queue\n", q.size);

    int temp_order, temp_qty;
    while (q.size > 0) {
        dequeue_struct(&q, &temp_order, &temp_qty);
    }

    return 0;
}
