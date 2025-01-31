#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct Node{
    int value;
    struct Node * next;
}Node;

typedef struct Stack{
    struct Node * head;
}Stack;

Node * createNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> value = data;
    newNode -> next = NULL;
    return newNode;
}

bool isEmpty(Stack * stack){
    return (stack -> head == NULL);
}

int size(Stack *stack){
    int count = 0;
    Node *ptr = stack->head;
    while(ptr){
        count++;
        ptr = ptr->next;
    }
    return count;
}

void push(Stack * stack, int data){
    Node * newNode = createNode(data);

    newNode -> next = stack -> head;

    stack -> head = newNode;
}

int pop(Stack * stack){

    if(isEmpty(stack)){
        printf("Stack is empty.\n");
        return -1;
    }

    Node * temp = stack -> head;
    int poppedData = temp->value;
    stack -> head = stack -> head -> next;
    free(temp);
    return poppedData;
}

int top (Stack * stack){
    
    if(!isEmpty(stack)) return stack -> head -> value;
    else{
        printf("Stack is empty\n");
        return INT_MIN;
    } 
}

void enqueue(Stack * stack, int data){
    push(stack, data);
}

void dequeue(Stack *stack){
    if(isEmpty(stack)){
        printf("Queue is empty.\n");
        return;
    }
    if(size(stack)==1){
        printf("Popped: %d\n", pop(stack));
        return;
    }
    int latestNode = pop(stack);
    dequeue(stack);
    push(stack, latestNode);
}

void peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Queue is empty.\n");
        return;
    }
    if(size(stack)==1){
        printf("Peek: %d\n", stack->head->value);
        return;
    }
    int latestNode = pop(stack);
    peek(stack);
    push(stack, latestNode);
}

void menuSystem() {
    Stack *queue = (Stack *)malloc(sizeof(Stack));
    queue->head = NULL;
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
            default:
                free(queue);
                break;
        }
    }
}

int main(){
    menuSystem();
    return 0;
}