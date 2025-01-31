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

void push(Stack * stack, int data){
    Node * newNode = createNode(data);

    newNode -> next = stack -> head;

    stack -> head = newNode;
}

void pop(Stack * stack){

    if(isEmpty(stack)){
        printf("Stack is empty.\n");
        return;
    }

    Node * temp = stack -> head;

    stack -> head = stack -> head -> next;

    free(temp);
}

int peek (Stack * stack){
    
    if(!isEmpty(stack)) return stack -> head -> value;
    else{
        printf("Stack is empty\n");
        return INT_MIN;
    } 
}

int size (Stack * stack){
    int count=0;
    if(isEmpty(stack)){
        return count;
    }
    Node * ptr = stack->head;
    while(ptr){
        count++;
        ptr=ptr->next;
    }
    return count++;
}

void menuSystem(){
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
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
            pop(stack);
            break;
        case 3:
            printf("Peek: %d\n", peek(stack));
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