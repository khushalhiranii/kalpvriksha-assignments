#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct Queue{
    Node * front;
    Node * rear;
}Queue;

Node * createNode(int value){
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
    return new;
}

bool isEmpty(Queue *queue){
    if(queue->front == NULL){
        return true;
    }
    return false;
}

void enqueue(Queue *queue, int data){
    Node * newNode = createNode(data);
    if(queue->front == NULL){
        queue->front = queue->rear = newNode;
    }else{
        queue->rear->next = newNode;
        queue->rear=newNode;
    }
}

void dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    
    Node * temp = queue->front;
    printf("Dequeued: %d\n", queue->front->data);
    queue->front = queue->front->next;

    if(queue->front == NULL) queue->rear = NULL;
    free(temp);
}

void peek(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty.\n");
        return;
    }
    printf("Peek element is: %d\n", queue->front->data);
}

int size (Queue * queue){
    int count=0;
    if(isEmpty(queue)){
        return count;
    }
    Node * ptr = queue->front;
    while(ptr != NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
}

int main(){
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    enqueue(queue, 10);
    enqueue(queue, 21);
    printf("Size of queue: %d\n", size(queue));
    dequeue(queue);
    enqueue(queue, 42);
    dequeue(queue);
    dequeue(queue);
    peek(queue);
    printf("Size of queue: %d\n", size(queue));
    return 0;
}