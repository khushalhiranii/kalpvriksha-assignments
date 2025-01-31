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

void menuSystem() {
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
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