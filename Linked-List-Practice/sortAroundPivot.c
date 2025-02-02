#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

void swap(Node *first, Node *second){
    int temp = first->value;
    first->value = second->value;
    second->value = temp;
}

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
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

Node *findPivot(Node *head, int pivot){
    Node *ptr = head;
    printf("%d\n", head->value);
    while(ptr){
        if(ptr->value == pivot){
            return ptr;
        }
        ptr = ptr->next;
    }
}

Node *sortAroundPivot(Node *head, int pivot){
    printList(head);
    Node *ptr = head;
    
    Node *pivotNode = findPivot(head, pivot);
    // printf("%d %d\n", ptr->value, head->value);
    Node *lastMinimum = createNode(-1);
    lastMinimum->next = head;
    
    while(ptr){
        // printf("%d %d\n", ptr->value, pivot);
        if(ptr->value <= pivot){
            // printf("Smaller: %d\n", ptr->value);
            swap(ptr, lastMinimum->next);
            lastMinimum = lastMinimum->next;
        }
        printList(head);
        ptr = ptr->next;
    }
    // swap(pivotNode, lastMinimum->next);
    return head;
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
    int pivot;
    printf("Enter pivot element: ");
    scanf("%d", &pivot);
    head = sortAroundPivot(head, pivot);
    printList(head);
}

int main(){
    takeInput();
    return 0;
}