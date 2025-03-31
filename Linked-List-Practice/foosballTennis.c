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
    Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void dividePlayers(Node *foosball, Node *tennis){
    Node *commonPlayers = NULL;
    Node *uniquePlayers = NULL;
    Node *ptr1 = foosball;
    while(ptr1){
        Node *ptr2 = tennis;
        int found = 0;
        while(ptr2){
            if(ptr1->value == ptr2->value){
                found=1;
            }
            ptr2 = ptr2->next;
        }
        if (found==1)  commonPlayers = createList(commonPlayers, ptr1->value);
        else uniquePlayers = createList(uniquePlayers, ptr1->value);
        ptr1 = ptr1->next;
    }

    ptr1 = tennis;
    while(ptr1){
        Node *ptr2 = commonPlayers;
        int found = 0;
        while(ptr2){
            if(ptr1->value == ptr2->value){
                found=1;
            }
            ptr2 = ptr2->next;
        }
        if (!found)  uniquePlayers = createList(uniquePlayers, ptr1->value);
        ptr1 = ptr1->next;
    }
    printList(commonPlayers);
    printList(uniquePlayers);
}

void takeInput(){
    int size;
    Node *head = NULL;
    printf("Enter size of 1st linked list: ");
    scanf("%d", &size);
    for(int i=0; i<size; i++){
        int element;
        printf("Enter element at index %d of 1st linked list: ", i+1);
        scanf("%d", &element);
        head = createList(head, element);
    }
    int size2;
    Node *head2 = NULL;
    printf("Enter size of 2nd linked list: ");
    scanf("%d", &size2);
    for(int i=0; i<size2; i++){
        int element;
        printf("Enter element at index %d of 2nd linked list: ", i+1);
        scanf("%d", &element);
        head2 = createList(head2, element);
    }
    // reorderLinkedList(head);
    dividePlayers(head, head2);
    // printList(head);
}

int main(){
    takeInput();
    return 0;
}