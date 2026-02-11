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
            // เรียก Dequeue
            x = dequeue_struct(&q);
            
            // ถ้าไม่ใช่ 0 แสดงว่ามีของออกมา (ถ้า 0 คือ Empty queue ปริ้นไปแล้ว)
            if(x != 0) {
                 printf("dequeing %d\n", x); // <--- แก้เป็นตัวเล็กตามที่คุณเคยใช้
            }
        }
        else {
            // เรียก Enqueue (ห้ามปริ้นอะไรออกมาตรงนี้ ถ้าโจทย์ไม่สั่ง)
            enqueue_struct(&q, atoi(argv[i]));
        }
    }
    return 0;
}