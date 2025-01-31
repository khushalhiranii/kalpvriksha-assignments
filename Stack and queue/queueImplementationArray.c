#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int *array;
    int front;
    int rear;
    unsigned capacity;
} Queue;

Queue *initializeQueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int *)malloc(capacity * sizeof(int));
    return queue;
}

bool isEmpty(Queue *queue)
{
    if ((queue->front == -1 && queue->rear == -1))
        return true;
    return false;
}

void enqueue(Queue *queue, int data){
    if(queue->capacity-1 == queue->rear){
        printf("Queue in filled\n");
        return;
    }
        if(queue->front == -1){
            queue->front = 0;
        }
        queue->rear++;
        queue->array[queue->rear] = data;
        printf("element added is : %d and rear is %d \n", queue->array[queue->rear], queue->rear);

        
    
    
}

void dequeue(Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued: %d", queue->array[queue->front]);
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
        return;
    }
    queue->front++;
    return;
}

void peek(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    printf("Peek: %d", queue->array[queue->front]);
    return;

}

int size(Queue *queue){
    if(isEmpty(queue)){
        return 0;
    }
    return (queue->rear - queue->front + 1);
}

int main(){
    Queue *queue = initializeQueue(5);
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