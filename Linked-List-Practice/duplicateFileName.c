#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Node{
    char *filename;
    struct Node *next;
}Node;

Node *createNode(char *file){
    Node *new = (Node *)malloc(sizeof(Node));
    new->filename = file;
    new->next = NULL;
    return new;
}

bool compareStrings(char *first, char *second){

    if(strlen(first) == strlen(second)){
        char *ptr1 = first;
        char *ptr2 = second;
        while(*ptr1 && *ptr2){
            if(*ptr1 != *ptr2){
                return false;
            }
            ptr1++;
            ptr2++;
        }
        return true;
    }
    return false;
}

Node *createList(Node *head, char *file){
    Node *new = createNode(file);
    if( head == NULL){
        head = new;
    }else{
        Node *ptr = head;
        Node *prev = NULL;
        bool found=0;
        while(ptr){
            prev = ptr;
            if(compareStrings(file, ptr->filename)){
                found=1;
                break;
            }
            ptr = ptr->next;
        }
        if(!found){
            prev->next = new;
        }
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
        printf("%s ", curr->filename);
        curr = curr->next;
    }
    printf("\n");
}



void takeInput(){
    int size, k;
    Node *head = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    for(int i=0; i<size; i++){
        char *element = (char *)malloc(100 * sizeof(char));
        printf("Enter file at index %d of linked list: ", i+1);
        scanf("%s", element);
        // printf("%s ", element);
        head = createList(head, element);
    }
    printList(head);
}

int main(){
    takeInput();
    return 0;
}