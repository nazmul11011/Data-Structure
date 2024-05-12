#include <stdio.h>

#define Q_SIZE 5

typedef struct{
    int head,tail;
    int data[Q_SIZE+1];
} Queue;

void enqueue(Queue *q, int item){
    if((q->tail+1) % (Q_SIZE+1) == q->head){
        printf("Queue is full");
        return;
    }

    q->data[q->tail] = item;
    q->tail = (q->tail+1) % (Q_SIZE+1);
}

int dequeue(Queue *q){
    int item;
    if(q->tail == q->head){
        printf("Queue is empty\n");
        return -1;
    }

    item = q->data[q->head];
    q->head = (q->head+1) % (Q_SIZE+1);
    return item;
}

int main(){

    Queue my_queue;
    
    int item;

    my_queue.head = 0;
    my_queue.tail = 0;

    enqueue(&my_queue, 1);
    printf("Tail = %d\n", my_queue.tail);
    enqueue(&my_queue, 2);
    printf("Tail = %d\n", my_queue.tail);

    printf("Beginning of the head = %d\n", my_queue.head);
    item = dequeue(&my_queue);
    printf("Item = %d, Head = %d\n", item, my_queue.head);
    item = dequeue(&my_queue);
    printf("Item = %d, Head = %d\n", item, my_queue.head);
    item = dequeue(&my_queue);
    printf("Item = %d, Head = %d\n", item, my_queue.head);

    return 0;
}