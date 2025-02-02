#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack{
    int size;
    int *arr;
    int top;
 }Stack;

 bool isEmpty(Stack *stack){
    return (stack->top == -1);
 }

 void push(Stack *stack, int value){
    stack->arr[++stack->top] = value;
 }

 void pop(Stack *stack){
    if(isEmpty(stack)){
        return;
    }
    // return stack->arr[stack->top--];
    stack->top--;
 }

void nextGreaterElements(int* nums, int numsSize) {
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(2 * numsSize * sizeof(int));
    stack->size = numsSize;
    stack->top = -1;
    int *ans = (int *)malloc(numsSize * sizeof(int));
    int itr = numsSize -1;
    while(itr>=0){
        push(stack, nums[itr]);
        itr--;
    }
    for(int i=numsSize-1; i>=0; i--){
        while(!isEmpty(stack) && stack->arr[stack->top]<=nums[i]){
            pop(stack);
        }
        ans[i] = (isEmpty(stack)) ? -1 : stack->arr[stack->top];
        push(stack, nums[i]);
    }
    for(int i=0; i<numsSize; i++){
        printf("%d ", ans[i]);
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
    nextGreaterElements(arr, size);

}

int main(){
    takeInput();
    return 0;
}