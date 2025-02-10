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

Node *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    Node *ptr1 = headA;
    Node *ptr2 = headB;
    int i=0;
    while(i<3){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(ptr1 == NULL){
            ptr1 = headB;
            i++;
        }
        if(ptr2 == NULL){
            ptr2 = headA;
            i++;
        }
    }
    return NULL;
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
    printf("Intersection = %d", getIntersectionNode(head1, head2));
}

int main(){
    takeInput();
    return 0;
}