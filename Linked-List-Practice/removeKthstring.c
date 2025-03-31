#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char *name;
    struct Node * next;
}Node;

Node * createNode(char *name){
    Node * new = (Node *)malloc(sizeof(Node));
    new->name = name;
    new->next = NULL;
    return new;
}

Node * createList(Node * head, char *value){
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

void printList(Node *head) {
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%s ", curr->name);
        curr = curr->next;
    }
    printf("\n");
}

Node * deleteNthFromEnd(Node * head, int n, int size){
    if(size-n==0){
        head = head->next;
        return head;
    }
    Node * ptr = head;
    for(int i=1; i<size-n; i++){
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    return head;
}

void inputForDelete(Node * head, int size){
    int delete;
    printf("Enter index from last to delete: ");
    scanf("%d", &delete);
    if(delete>size || delete<=0){
        printf("Invalid position");
        return;
    }
    head = deleteNthFromEnd(head, delete, size);

    printList(head);
}

void inputForList(int size){
    Node * head = NULL;
    int i=0;
    while(i<size){
        char *data = (char *)malloc(100 * sizeof(char));
        printf("Enter %d element: ", i+1);
        scanf(" %[^\n]", data);
        head = createList(head, data);
        i++;
    }
    inputForDelete(head, size);
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