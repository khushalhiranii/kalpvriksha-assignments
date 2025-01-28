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
    return new;
}

Node * findMiddle(Node * start, Node * end){
    Node * slow = start;
    Node * fast = start;
    while(fast != end && fast->next != end){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void binarySearch(Node * head, int search){
    Node * start = head;
    Node * end = NULL;

    while(start != end){
        Node * mid = findMiddle(start, end);
        if(mid == NULL){
            printf("-1\n");
            return;
        }
        if(mid->data == search){
            printf("%d", mid->data);
            return;
        }
        if( search < mid->data ){
            end = mid;
        }else{
            start = mid->next;
        }
    }
    printf("-1\n");
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
    int search;
    printf("Enter element to search: ");
    scanf("%d", &search);
    binarySearch(head, search);
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