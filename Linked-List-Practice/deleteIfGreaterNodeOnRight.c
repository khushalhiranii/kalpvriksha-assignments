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
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

Node * deleteNodesWithGreaterRightNodes(Node *head){
    Node *ptr = head;
    Node *prev = createNode(-1);
    prev->next = head;
    while(ptr->next){
        if(ptr->value < ptr->next->value){
            Node *temp = ptr;
            prev->next = ptr->next;
            if(ptr == head) head = ptr->next;
            ptr = ptr->next;
            free(temp);
            continue;
        }
        prev = ptr;
        ptr = ptr->next;
    }
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
    head = deleteNodesWithGreaterRightNodes(head);
    printList(head);
}

int main(){
    takeInput();
    return 0;
}