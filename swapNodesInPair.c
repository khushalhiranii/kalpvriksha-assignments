#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node * createNode(int value){
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
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

Node* swapPairs(Node* head) {

    if(!head || !head->next) return head;
    Node * ptr = head;
    Node * newHead = head->next;
    while(ptr && ptr->next ){
        Node * next_ = ptr->next;
        ptr->next = next_->next;
        next_->next = ptr;
        if(ptr->next && ptr->next->next){
            Node * temp = ptr->next;
            ptr->next = ptr->next->next;
            
            ptr = temp;
        }else{
            ptr = ptr->next;
        }
    }
    return newHead;
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
    head = swapPairs(head);

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