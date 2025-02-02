#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

Node *createNode(int data){
    Node *new = (Node *)malloc(sizeof(Node));
    new->value = data;
    new->next = NULL;
    return new;
}

void push(Stack *stack, int value){
    Node *new = createNode(value);
    new->next = stack->top;
    stack->top = new;
}

bool isEmpty(Stack *stack){
    return (stack->top == NULL);
}

void pop(Stack *stack){
    if(stack -> top == NULL){
        printf("Stack is empty\n");
        return;
    }
    Node * tempNode = stack->top;
    int temp = stack->top->value;
    stack->top = stack->top->next;
    free(tempNode);
    return;
}

void previousSmallerElement(int arr[], int size){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    int ans[100];
    for(int i=0; i<size; i++){
        while(!isEmpty(stack) && stack->top->value >arr[i]){
            pop(stack);
        }
        if(isEmpty(stack)){
            printf("-1");
        }else{
            printf("%d ", stack->top->value);
        }
        push(stack, arr[i]);
    }
}

void takeInput(){
    int arr[100];
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    for(int i =0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    previousSmallerElement(arr, size);
}

int main(){
    takeInput();
    return 0;
}