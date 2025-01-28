#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

void printList(Node *head) {
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

Node * split(Node * head){
    Node * fast = head;
    Node * slow = head;

    while( fast != NULL && fast->next != NULL ){
        fast = fast->next->next;
        if(fast != NULL) slow = slow->next;
    }

    Node * secondHalf = slow->next;
    slow->next = NULL;
    return secondHalf;
}

Node * merge(Node * first, Node * second){
    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->data < second->data){
        first->next = merge(first->next, second);
        return first;
    }
    else{
        second->next = merge(first, second->next);
        return second;
    }
}

Node * mergeSort(Node * head){
    if(head ==NULL || head->next == NULL) return head;

    Node * second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

Node * createNode(int value){
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
    return new;
}

Node * createList(Node * head, int value){
    Node * new = createNode(value);
    if(head == NULL){
        head = new;
    }else{
        Node * ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

void inputForList(int size){
    int first;
    printf("Enter 1 element: ");
    scanf("%d", &first);
    Node * head = createNode(first);
    int i=1;
    while(i<size){
        int data;
        printf("Enter %d element: ", i+1);
        scanf("%d", &data);
        head = createList(head, data);
        i++;
    }
    head = mergeSort(head);
    printList(head);
}



void takeInput(){
    int size;
    printf("Enter size of Linked List: ");
    scanf("%d", &size);
    if(size<=0){
        printf("Invalid input");
        return;
    }
    
    inputForList(size);

    
}

int main(){
 takeInput();
 return 0;
}