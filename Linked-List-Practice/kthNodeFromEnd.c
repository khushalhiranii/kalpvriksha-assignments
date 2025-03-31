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
}

Node *createList(Node *head, int data){
    Node *new = createNode(data);
    if(head == NULL){
        return new;
    }else{
        Node *ptr = head;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
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

void printKthNodeFromEnd(Node *head, int size, int k){
    Node *ptr = head;
    printList(head);
    printf("%d %d\n", size, k);
    for(int i=0; i<size-k; i++){
        ptr = ptr->next;
    }
    printf("Node at %d from end is: %d", k, ptr->value);
}

void takeInput(){
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    Node *head = NULL;
    for(int i=0; i<size; i++){
        int element;
        printf("Enter element at %d: ", i+1);
        scanf("%d", &element);
        head = createList(head, element);
    }
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    if(k>size){
        printf("Invalid node to show.");
        return;
    }
    printKthNodeFromEnd(head, size, k);
}

int main(){
    takeInput();
}