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

int multiplyNodes(Node *first, Node *second){
    printList(first);
    printList(second);
    Node *ptr1 = first;
    int sum=0;
    while(ptr1){
        int nodeSum=0;
        Node *ptr2 = second;
        while(ptr2){
            nodeSum = nodeSum * 10 + (ptr1->value * ptr2->value);
            ptr2 = ptr2->next;
        }
        sum = sum * 10 + nodeSum; 
        ptr1 = ptr1->next;
    }
    return sum;
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
    printf("Product = %d", multiplyNodes(head1, head2));
    // head = deleteNodesWithGreaterRightNodes(head);
    // printList(head);
}

int main(){
    takeInput();
    return 0;
}