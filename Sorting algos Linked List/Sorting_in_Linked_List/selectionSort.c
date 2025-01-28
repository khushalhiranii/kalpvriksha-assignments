#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
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

void selectionSort(Node * head, int size){
    Node * ptr = head;
    for(Node * itr = ptr; itr->next != NULL; itr= itr->next){
        Node * max = itr;
        for(Node * curr = itr->next; curr != NULL; curr= curr->next){
            if(curr->data < max->data){
                max = curr;
            }
        }
        if(itr != max){
            swap(itr, max);
        }
    }
    printList(head);
}

Node * createNode(int value){
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
    new->prev = NULL;
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
        new->prev = ptr;
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
    selectionSort(head, size);
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