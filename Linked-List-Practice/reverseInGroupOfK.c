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

Node *reverseInGroupOfK(Node *head, int k){
    if(head == NULL) return head;
    Node *checkNull=head;
    int i=0;
    while(i<k){
        if(!checkNull) return head;
        checkNull = checkNull->next;
        i++;
    }
    i=0;
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while(curr && i<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    head->next = reverseInGroupOfK(next, k);
    return prev;
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
    head = reverseInGroupOfK(head, k);
    printList(head);
}

int main(){
    takeInput();
    return 0;
}