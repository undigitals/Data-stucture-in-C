//
//  main.c
//  queueINclass
//
//  Created by Umid Negmatullayev on 4/9/18.
//  Copyright © 2018 Umid Negmatullayev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// declaring node
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}snode;

// declaring queue

    snode* front=NULL;
    snode* rear=NULL;

//initializing queue

// initializing node
snode* createNode(int x){
    snode* newNode = (snode*)malloc(sizeof(snode));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// just a dummy nodes
//now by creating this we dont need to check if the queue is empty
//because there is always node in the queue
void createSentinels(){
    front=createNode(0);
    rear=createNode(0);
    front->next=rear;
    rear->prev=front;
}


// enqueing at the front
/*==== 1. we are assigning the next to the temp =====*/
void enqueueAtFront(int x){
    snode* newNode = createNode(x);
    snode* temp;
    
    temp=front->next;
    front->next=newNode;
    newNode->next=temp;
    temp->prev=newNode;
    newNode->prev=front;
}

// enqueueing at the rear
void enqueueAtRear(int x){
    snode* newNode = createNode(x);
    snode* temp;
    
    temp = rear->prev;
    temp->next = newNode;
    newNode->next = rear;
    rear->prev = newNode;
    newNode->prev=temp;
}

// dequeueign at the front
void dequeueAtFront(){
    snode* temp;
    temp=front->next;
    front->next=temp->next;
    temp->next->prev=front;
    free(temp);
}

// dequeueing at the rear
void dequeuAtRear(){
    snode* temp;
    temp=rear->prev;
    rear->prev=temp->prev;
    temp->prev->next=rear;
    free(temp);
}

void display(){
    snode* temp;
    for(temp=front->next;temp!=rear;temp=temp->next){
        printf("%i\t",temp->data);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int choice, item;
    createSentinels();
    
    while(1){
        printf("\n 1.Enqueue at Front: \n");
        printf("\n 2.Enqueue at Rear: \n");
        printf("\n 3.Dequeue at Front: \n");
        printf("\n 4.Dequeue at Rear: \n");
        printf("\n 5.Display: \n");
        printf("\n 6.Exit: \n");
        
        scanf("%i",&choice);
        
        switch (choice) {
            case 1:
                printf("\n1.Equeueing an item at Front:");
                scanf("%i", &item);
                enqueueAtFront(item);
                break;
            case 2:
                printf("\n2.Equeueing an item at Rear:");
                scanf("%i", &item);
                enqueueAtRear(item);
                break;
            case 3:
                printf("\n3.Dequeueing an item at Front:");
                dequeueAtFront();
                break;
            case 4:
                printf("\n4.Dequeueing an item at Rear:");
                dequeuAtRear();
                break;
            case 5:
                printf("\n5.Displaying an item:\n");
                display();
                break;
            case 6:
                exit(0);
            default:
                break;
        }
    }
    
    return 0;
}
