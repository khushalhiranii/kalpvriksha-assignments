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

Queue *pop(Queue *queue1){
    Queue * queue2 = (Queue *)malloc(sizeof(Queue));
    queue2->front = NULL;
    queue2->rear = NULL;
    for(int i=0; i<size(queue1)-1; i++){
        enqueue(queue2, dequeue(queue1));
    }
    int poppedData = dequeue(queue1);
    printf("%d\n", poppedData);
    return queue2;
    
}

int top(Queue *queue){
    return queue->rear->data;
}

void menuSystem(){
    Queue * stack = (Queue *)malloc(sizeof(Queue));
    stack->front = NULL;
    stack->rear = NULL;

    printf("Enter 1 for push, 2 for pop, 3 for peek, 4 for size and 0 for exit\n");
    int operation=1;
    while(operation > 0 && operation <= 4){
        printf("Enter the operation: ");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            int element;
            printf("Enter the element to push: ");
            scanf("%d", &element);
            push(stack, element);
            break;
        case 2:
            stack = pop(stack);
            break;
        case 3:
            printf("Peek: %d\n", top(stack));
            break;
        case 4:
            printf("Size: %d\n", size(stack));
            break;
        default:
            break;
        }
    }
}

int main(){
    menuSystem();
    return 0;
}