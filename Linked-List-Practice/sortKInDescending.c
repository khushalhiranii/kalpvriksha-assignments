#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *createNode(int value){
    Node *new = (Node *)malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    return new;
}

Node *createList(Node *head, int value){
    Node *new = createNode(value);
    if(head == NULL){
        head = new;
        return head;
    }
    Node *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next=new;
    return head;
}

void printList(Node *head){
    if(!head){
        printf("List is empty.\n");
        return;
    }
    Node *ptr = head;
    while(ptr){
        printf("%d", ptr->value);
        ptr=ptr->next;
        if(ptr) printf("->");
    }
    return;
}

void swap(Node *a, Node *b){
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
    return;
}

void bubbleSort(Node *head){
    Node *ptr = head;
    int swapped = 1;
    Node *tail = NULL;
    while(swapped){
        ptr = head;
        swapped = 0;
        while(ptr && ptr->next != tail){
            if(ptr->value < ptr->next->value){
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        tail = ptr;
    }
}

void sortKInDescending(Node *head, int k){
    Node *ptr = head;
    while(ptr){
        Node *first = ptr;
        int i=0;
        for(i=0; i<k-1; i++){
            if(ptr->next) ptr = ptr->next;
            else break;
        }
        if(ptr && i==k-1){
            Node *temp= ptr->next;
            ptr->next = NULL;
            bubbleSort(first);
            ptr->next = temp;
        }
        ptr = ptr->next;
    }
    
}

void takeInput(){
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    Node *head = NULL;
    for(int i=0; i<size; i++){
        int element;
        printf("Enter element at index %d: ", i+1);
        scanf("%d", &element);
        head = createList(head, element);
    }
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    sortKInDescending(head, k);
    printList(head);
}

int main(){
    takeInput();
}