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
        new->next = head;
    }else{
        Node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = head;
    }
    return head;
}

void printList(Node *head) {
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct Node *curr = head;
    while (curr->next != head) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("%d ", curr->value);
    printf("\n");
}

Node *roundwiseElimination(Node *head, int k) {
    Node *ans = NULL;
    if (head == NULL || k <= 0) return head;

    Node *ptr = head;
    Node *prev = NULL;


    while (head->next != head) {
        for (int i = 1; i < k; i++) {
            prev = head;
            head = head->next;
        }
        ans = createList(ans, head->value);
        prev->next = head->next;
        free(head);
        head = prev->next;
    }
    ans = createList(ans, head->value);
    return ans;
}

void takeInput(){
    int size, k;
    Node *head = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    printf("Enter k: ");
    scanf("%d", &k);
    for(int i=0; i<size; i++){
        int element;
        printf("Enter element at index %d of linked list: ", i+1);
        scanf("%d", &element);
        head = createList(head, element);
    }
    head = roundwiseElimination(head, k);
    printList(head);
}

int main(){
    takeInput();
    return 0;
}