#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum { Critical, Serious, Stable }PatientType;

typedef struct Node{
    int id;
    PatientType type;
    char name[20];
    struct Node *next;
}Node;

void printList(Node *head){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    Node *ptr = head;
    while(ptr){
        printf("%d ", ptr->id);
        if(ptr->type == 0)printf("Critical ");
        if(ptr->type == 1)printf("Serious ");
        if(ptr->type == 2)printf("Stable ");
        printf("%s\n", ptr->name);
        ptr=ptr->next;
    }
    return;
}

Node *createNode(int id, PatientType type, char name[]){
    Node *new = (Node *)malloc(sizeof(Node));
    new->id = id;
    new->type = type;
    strcpy(new->name, name);
    new->next = NULL;
    return new;
}

Node *createList(Node *head, int id, PatientType type, char name[]){
    Node *new = createNode(id, type, name);
    Node *ptr = head;
    
    if(head == NULL){
        return new;
    }
    if(ptr->type > type){
        new->next = ptr;
        return new;
    }
    while(ptr->next != NULL && ptr->next->type <= type){
        ptr=ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
    return head;
}



void takeInput(){
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    Node *head = NULL;
    for(int i=0; i<size; i++){
        int id;
        char type[10];
        char name[20];
        printf("Enter patient detail: ");
        scanf("%d %s %s", &id, type, name);
        PatientType enumType;
        if(strcmp(type, "Critical") == 0 ) enumType=0;
        else if(strcmp(type, "Serious") == 0) enumType=1;
        else enumType=2;
        head = createList(head, id, enumType, name);
    }
    printList(head);
}

int main(){
    takeInput();
}