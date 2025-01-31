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

int main(){
    Stack * stack;
    stack -> head = NULL;
    push(stack, 10);
    printf("Peek element is: %d\n", peek(stack));
    push(stack, 21);
    printf("Peek element is: %d\n", peek(stack));
    push(stack, 30);
    printf("Peek element is: %d\n", peek(stack));
    pop(stack);
    printf("Peek element is: %d\n", peek(stack));
    pop(stack);
    printf("Peek element is: %d\n", peek(stack));
    pop(stack);
    printf("Peek element is: %d\n", peek(stack));
    printf("Size of stack: %d\n", size(stack));
    return 0;
}