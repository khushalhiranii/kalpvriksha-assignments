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
}

void dequeue(Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
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
    printf("Peek: %d\n", queue->array[queue->front]);
    return;

}

int size(Queue *queue){
    if(isEmpty(queue)){
        return 0;
    }
    return (queue->rear - queue->front + 1);
}

void menuSystem() {
    unsigned capacity;
    printf("Enter queue capacity: ");
    scanf("%u", &capacity);

    Queue *queue = initializeQueue(capacity);
    int choice, value;

    while (1) {
        printf("Enter 1 for enqueue, 2 for dequeue, 3 for peek, 4 for size and 0 for exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                peek(queue);
                break;
            case 4:
                printf("Size: %d\n", size(queue));
                break;
            case 0:
                free(queue->array);
                free(queue);
                return;
            default:
                break;
        }
    }
}

int main(){
    menuSystem();
    return 0;
}