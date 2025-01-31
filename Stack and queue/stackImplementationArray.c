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

Stack * initializeStack(){
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack -> capacity = 1000;
    stack -> top = -1;
    stack -> array = (int *)malloc(stack->capacity * sizeof(int));
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
        return -1;
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

void menuSystem(){
    Stack * stack = initializeStack();
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
            printf("Size: %d\n", stack->top+1);
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