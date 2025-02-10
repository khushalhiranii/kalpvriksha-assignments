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

Node* addNumbers(Node* l1, Node* l2, int carry) {
    if (l1 == NULL && l2 == NULL && carry == 0) {
        return NULL;
    }
    int sum = (l1 ? l1->value : 0) + (l2 ? l2->value : 0) + carry;
    carry = (sum > 9) ? 1 : 0;

    Node * newNode = createNode(sum%10);

    Node * nextNode = addNumbers(((l1) ? l1->next : NULL), ((l2) ? l2->next : NULL), carry);
    newNode->next = nextNode;
    return newNode;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    return addNumbers(l1, l2, 0);
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
    printList(addTwoNumbers(head1, head2));
}

int main(){
    takeInput();
    return 0;
}