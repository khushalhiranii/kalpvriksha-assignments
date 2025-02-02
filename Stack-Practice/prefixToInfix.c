#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char *equation;
    struct Node *next;
}Node;

typedef struct Stack{
    Node * top;
 }Stack;

Node *createNode(char *ch){
    Node *new = (Node *)malloc(sizeof(Node));
    new->equation = strdup(ch);;
    new->next = NULL;
    return new;
}

void push(Stack *stack, char *ch){
    Node *new = createNode(ch);
    new->next = stack->top;
    stack->top = new;
}

char *pop(Stack *stack){
    if(stack->top == NULL){
        printf("Stack is empty");
        return NULL;
    }
    Node *temp = stack->top;
    char *equation = temp->equation;
    stack->top = stack->top->next;
    free(temp);
    return equation;
}

char *addStrings(char *first, char *operator, char *second){
    char *newEquation = (char *)malloc((strlen(first) + strlen(second) + 4) * sizeof(char));
    strcpy(newEquation, "(");
    strcat(newEquation, first);
    strcat(newEquation, operator);
    strcat(newEquation, second);
    strcat(newEquation, ")");
    
    return newEquation;
}

char *prefixToInfix(char *string){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top=NULL;

    for(int i=strlen(string); i>=0; i--){
        if ((string[i] != '+') && (string[i] != '-') && (string[i] != '*') && (string[i] != '/')) {
            char operand[2] = {string[i], '\0'};
            push(stack, operand);
        }else{
            char *first = pop(stack);
            char *second = pop(stack);
            char operator[2] = {string[i], '\0'};
            char *newEquation = addStrings(first, operator, second);
            free(first);
            free(second);
            push(stack, newEquation);
        }
    }
    return pop(stack);
}

void takeInput(){
    char *string = (char *)malloc(100 * sizeof(char));
    printf("Enter prefix to be evaluated: ");
    scanf("%s", string);
    string = prefixToInfix(string);
    printf("%s", string);
    return;
}

int main(){
    
    takeInput();
}