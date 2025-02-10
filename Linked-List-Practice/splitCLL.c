#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int data){
    Node *new = (Node *)malloc(sizeof(Node));
    new->value = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

Node *createList(Node *head, int data){
    Node *new = createNode(data);
    if( head == NULL){
        head = new;
        new->next = head;
    }else{
        Node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
        new->prev = ptr;
    }
    return head;
}

void printList(Node *head) {
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

Node *findMiddle(Node *head){
    Node *fast = head;
    Node *slow = head;
    while(fast->next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast->next == head) fast->next = NULL;
    else if(fast->next->next == head) fast->next->next = NULL;
    return slow;
}

void split(Node *head){
    // printList(head);
    Node *second = findMiddle(head);
    Node *temp = second->next;
    second->next = NULL;
    printList(head);
    printList(temp);
    return;
}

void takeInput(){
    int size, k;
    Node *head = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    for(int i=0; i<size; i++){
        int element;
        printf("Enter element at index %d of linked list: ", i+1);
        scanf("%d", &element);
        head = createList(head, element);
    }
    split(head);
}

int main(){
    takeInput();
    return 0;
}