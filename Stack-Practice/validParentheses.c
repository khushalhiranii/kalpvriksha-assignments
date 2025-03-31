#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Stack{
    char arr[100];
    int top;
}Stack;

void push(Stack *stack, char ch){
    stack->arr[++stack->top] = ch;
}

void pop(Stack *stack){
    stack->top--;
}

void validParentheses(char string[]){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    for(int i=0; i<strlen(string); i++){
        if(string[i] == '(' || string[i] == '{' || string[i] == '['){
            push(stack, string[i]);
        }
        else if(string[i] == ')' || string[i] == '}' || string[i] == ']'){
            char ch = string[i];
            if(stack->top == -1){
                printf("Invalid");
                return;
            }
            char topChar = stack->arr[stack->top];

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                printf("Invalid");
                return;
            }
            pop(stack);
        }
    }
    if(stack->top == -1){
        printf("Valid");
        return;
    }else{
        printf("Invalid");
    }
}

void takeInput(){
    char string[100];
    scanf("%s", string);
    validParentheses(string);
}

int main(){
    takeInput();
}