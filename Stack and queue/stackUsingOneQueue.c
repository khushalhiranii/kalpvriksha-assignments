#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue* createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

Node* createNode(int value) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
    return new;
}

bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->front == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    Node* temp = queue->front;
    int frontData = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(temp);
    return frontData;
}

int size(Queue* queue) {
    int count = 0;
    Node* ptr = queue->front;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void push(Queue* queue, int data) {
    enqueue(queue, data);
    int queueSize = size(queue);
    
    for (int i = 0; i < queueSize - 1; i++) {
        enqueue(queue, dequeue(queue));
    }
}

void pop(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Popped: %d\n", dequeue(queue));
}

int top(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return queue->front->data;
}

void menuSystem() {
    Queue* stack = createQueue();

    printf("Enter 1 for push, 2 for pop, 3 for top, 4 for size, and 0 for exit\n");
    int operation = 1;
    while (operation > 0 && operation <= 4) {
        printf("Enter the operation: ");
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                int element;
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(stack, element);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                printf("Top: %d\n", top(stack));
                break;
            case 4:
                printf("Size: %d\n", size(stack));
                break;
            default:
                break;
        }
    }
}

int main() {
    menuSystem();
    return 0;
}
