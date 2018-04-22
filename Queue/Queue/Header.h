#ifndef Queue
#define Queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// defining queue
typedef struct QUEUE {
    void* buffer[10];
    int front;
    int rear;
    int cnt;
}QUEUE;

QUEUE* createQueue() {
    QUEUE* queue;
    queue = (QUEUE*)malloc(sizeof(QUEUE));
    
    if (queue) {
        queue->front = -1;
        queue->rear = -1;
        queue->cnt = 0;
    }
    return queue;
}

// function prototypes
bool enqueue(QUEUE* queue, void* data);
bool dequeue(QUEUE* queue, void** data);
bool isEmpty(QUEUE* queue);
bool isFull(QUEUE* queue);
bool peekRear(QUEUE* queue, void** data, int* index);
bool peekFront(QUEUE* queue, void** data);

// destroy
QUEUE* destroyQueue(QUEUE* queue){
    if(!(queue==NULL)){
        while(queue->front<=queue->rear){
            free(queue->buffer[queue->front]);
            queue->front=(queue->front+1)%10;
        }
        free(queue);
    }
    return queue;
}

bool enqueue(QUEUE* queue, void* data) {
    
    if (queue->cnt == 10) {
        return false;
    }
    if(queue->cnt==0){
        queue->front++;
    }
    queue->rear = (queue->rear + 1) % 10;
    (queue->buffer)[queue->rear] = data;
    
    
    (queue->cnt)++;
    return true;
}

bool dequeue(QUEUE* queue, void** data) {
    if (isEmpty(queue)) {
        return false;
    }
    
    if(queue->cnt==1){
        *data = (queue->buffer)[queue->front];
        queue->front=queue->rear=-1;
    }else{
        *data = (queue->buffer)[queue->front];
        queue->front = (queue->front + 1) % 10;
    }
    (queue->cnt)--;
    return true;
}

// is empty
bool isEmpty(QUEUE* queue) {
    return queue->cnt == 0;
}

// is full
bool isFull(QUEUE* queue) {
    return queue->cnt == 10;
}

// peekRear
bool peekRear(QUEUE* queue, void** data, int* index) {
    if (isEmpty(queue)) {
        return false;
    }
    *data = (queue->buffer)[queue->rear];
    *index = queue->rear;
    return true;
}

// frontRear
bool peekFront(QUEUE* queue, void** data) {
    if (isEmpty(queue)) {
        return false;
    }
    *data = (queue->buffer)[queue->front];
    
    return true;
}


#endif

