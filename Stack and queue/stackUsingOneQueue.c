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

int dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    
    Node * temp = queue->front;
    int frontData = temp->data;
    // printf("Dequeued: %d\n", queue->front->data);
    queue->front = queue->front->next;

    if(queue->front == NULL) queue->rear = NULL;
    free(temp);
    return frontData;
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

void push(Queue *queue, int data){
    enqueue(queue, data);
    return;
}

void pop(Queue *queue){
    for(int i=0; i<size(queue)-1; i++){
        int temp = dequeue(queue);
        enqueue(queue, temp);
    }
    int poppedData = dequeue(queue);
    printf("%d ", poppedData);
    return;
}

int top(Queue *queue){
    printf("%d", queue->rear->data);
}

int main(){
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    push(queue, 10);
    push(queue, 21);
    printf("Size of queue: %d\n", size(queue));
    pop(queue);
    push(queue, 42);
    pop(queue);
    pop(queue);
    push(queue, 21);
    push(queue, 12);
    push(queue, 33);
    pop(queue);
    top(queue);
    printf("Size of queue: %d\n", size(queue));
    return 0;
}