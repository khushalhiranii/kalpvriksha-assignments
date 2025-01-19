#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct LinkedList{
    Node * head;
    Node * tail;
}LinkedList;

Node * createNode(int node_data){
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = node_data;
    new->next = NULL;
    return new;
}

void insertAtBeginning(LinkedList * llist, int value){
    Node * new = createNode(value);
    if(llist->head == NULL && llist->tail == NULL){
        llist->tail = new;
    }else{
        new->next = llist->head;
    }
    llist->head = new;
}

void insertAtEnd(LinkedList * llist, int value){
    Node * new = createNode(value);
    if(llist->head == NULL && llist->tail == NULL){
        llist->head = new;
    }else{
        llist->tail->next = new;
    }
    llist->tail = new;
}

void insertAtPosition(LinkedList * llist, int position, int value){
    Node * new = createNode(value);
    if(position==1){
        insertAtBeginning(llist, value);
    }else if(position>1){
        Node * ptr = llist->head;
        for(int i=1; i<position-1; i++){
            if(ptr->next == NULL){
                printf("Invalid position\n");
                return;
            }
            ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
    }else{
        printf("Invalid position\n");
    }
}

void updateAtPosition(LinkedList * llist, int position, int value){
    if(position>=1){
        Node * ptr = llist->head;
        for(int i=1; i<position; i++){
            if(ptr == NULL){
                printf("Invalid position\n");
                return;
            }
            ptr = ptr->next;
        }
        ptr->data = value;
    }else{
        printf("Invalid position\n");
    }
}

void deleteAtBeginning(LinkedList * llist){
    
    if(llist->head == NULL && llist->tail == NULL){
        printf("Empty linked list\n");
    }else{
        Node * temp = llist->head;
        llist->head = llist->head->next;
        free(temp);
    }
}

void deleteAtEnd(LinkedList * llist){
    
    if(llist->head == NULL && llist->tail == NULL){
        printf("Empty linked list\n");
    }else{
        Node * ptr = llist->head;
        if(ptr == llist->tail){
            ptr == NULL;
            return;
        }
        while(ptr->next != llist->tail ){
            ptr = ptr->next;
        }
        Node * temp = llist->tail;
        llist->tail = ptr;
        ptr->next = NULL;
        free(temp);
    }
}

void deleteAtPosition(LinkedList * llist, int position){
    if (llist->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(position==1){
        deleteAtBeginning(llist);
    }else if(position>1){
        Node * ptr = llist->head;
        for(int i=1; i<position-1; i++){
            if(ptr->next == NULL){
                printf("Invalid position\n");
                return;
            }
            ptr = ptr->next;
        }
        if(ptr->next == NULL){
            printf("Invalid position\n");
            return;
        }
        if(ptr->next == llist->tail){
            deleteAtEnd(llist);
        }else{
            ptr->next = ptr->next->next;
        }
    }else{
        printf("Invalid position\n");
    }
}

void printList(LinkedList* llist) {
    Node* current = llist->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    LinkedList * llist = (LinkedList *)malloc(sizeof(LinkedList));
    llist->head = NULL;
    llist->tail = NULL;
    int numberOfOperations;
    scanf("%d", &numberOfOperations);
    for(int i=0; i<numberOfOperations; i++){
        int operation;
        scanf("%d", &operation);
        switch(operation){
            case 1:{
                int data;
                scanf("%d", &data);
                insertAtEnd(llist, data);
                break;
            }
            case 2:{
                int value;
                scanf("%d", &value);
                insertAtBeginning(llist, value);
                break;
            }
            case 3:{
                int position;
                scanf("%d", &position);
                int value;
                scanf("%d", &value);
                insertAtPosition(llist, position, value);
                break;
            }
            case 4:{
                printList(llist);
                break;
            }
            case 5:{
                int position;
                scanf("%d", &position);
                int value;
                scanf("%d", &value);
                updateAtPosition(llist, position, value);
                break;
            }
            case 6:{
                deleteAtBeginning(llist);
                break;
            }
            case 7:{
                deleteAtEnd(llist);
                break;
            }
            case 8:{
                int position;
                scanf("%d", &position);
                deleteAtPosition(llist, position);
                break;
            }
            default:{
                printf("Invalid input\n");
                return 0;
            }
        }

    }
    printList(llist);

    return 0;
}