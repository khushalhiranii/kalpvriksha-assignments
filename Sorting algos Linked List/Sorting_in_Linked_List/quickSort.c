#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

void swap(Node * a, Node * b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

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

Node * createNode(int value){
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
    return new;
}

Node * findPivot(Node * head){
    if( head == NULL || head->next == NULL ) return head;
    Node * ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr;
}

Node * NodeAfetrPartition(Node * head){
    if( head == NULL || head->next == NULL ) return head;
    Node * ptr = head;
    Node * pivot = findPivot(head);
    Node * lastMinimum = createNode(-1);
    lastMinimum->next = head;
    while(ptr != pivot){
        if( ptr->data < pivot->data ){
            swap(ptr, lastMinimum->next);
            lastMinimum = lastMinimum->next;
        }
        ptr = ptr->next;
    }
    swap(pivot, lastMinimum->next);
    return lastMinimum;
}

void quickSort(Node * head){
    if(head ==NULL || head->next == NULL) return;

    Node * second = NodeAfetrPartition(head);
    Node * temp = second->next;
    second->next = NULL;

    quickSort(head);
    quickSort(temp);

    second->next = temp;
    return ;
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
    quickSort(head);
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