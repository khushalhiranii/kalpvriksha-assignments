#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack{
    int top;
    unsigned capacity;
    int *array;
}Stack;

bool isEmpty(Stack * stack){
    return (stack -> top == -1);
}

Stack * initializeStack(unsigned capacity){
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int *)malloc(capacity * sizeof(int));
    return stack;
}

void push(Stack * stack, int data){
    if(stack->top == stack->capacity -1){
        printf("Stack is full.\n");
        return;
    }
    stack->array[++(stack->top)] = data;
}

int pop(Stack * stack){
    if(isEmpty(stack)){
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    return stack->array[(stack->top)--] ;
}

int peek(Stack * stack){
    if(isEmpty(stack)){
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    return stack->array[(stack->top)] ;
}

int main(){
Stack * stack = initializeStack(3);
    push(stack, 10);
    printf("Peek element is: %d\n", peek(stack));
    push(stack, 21);
    printf("Peek element is: %d\n", peek(stack));
    push(stack, 30);
    printf("Peek element is: %d\n", peek(stack));
    pop(stack);
    printf("Peek element is: %d\n", peek(stack));
    push(stack, 15);
    printf("Peek element is: %d\n", peek(stack));
    return 0;
}