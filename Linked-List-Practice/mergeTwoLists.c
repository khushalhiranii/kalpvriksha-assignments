#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *createNode(int data){
    Node *new = (Node *)malloc(sizeof(Node));
    new->value = data;
    new->next = NULL;
    return new;
}

Node *createList(Node *head, int data){
    Node *new = createNode(data);
    if( head == NULL){
        head = new;
    }else{
        Node *ptr = head;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

void printList(Node *head) {
    if(head == NULL){
        printf("List is empty");
        return;
    }
    Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

Node *createNode(int value) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    return new;
}

Node *createList(Node *head, int value) {
    Node *new = createNode(value);
    if (head == NULL) {
        head = new;
    } else {
        Node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

Node *mergeTwoSorted(Node *first, Node *second){
    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->value <= second->value){
        first->next = mergeTwoSorted(first->next, second);
        return first;
    }else{
        second->next = mergeTwoSorted(first, second->next);
        return second;
    }
}

void takeInput(){
    int size1;
    Node *head1 = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size1);
    for(int i=0; i<size1; i++){
        int element;
        printf("Enter element at index %d of linked list: ", i+1);
        scanf("%d", &element);
        head1 = createList(head1, element);
    }
    int size2;
    Node *head2 = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size2);
    for(int i=0; i<size2; i++){
        int element;
        printf("Enter element at index %d of linked list: ", i+1);
        scanf("%d", &element);
        head2 = createList(head2, element);
    }
    printf("Product = %d", addTwoNumbers(head1, head2));
}

int main(){
    takeInput();
    return 0;
}