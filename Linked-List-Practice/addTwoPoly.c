#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coefficient;
    int power;
    struct Node *next;
}Node;

Node *createNode(int coefficient, int power){
    Node *new = (Node *)malloc(sizeof(Node));
    new->coefficient = coefficient;
    new->power = power;
    new->next = NULL;
    return new;
}

Node *createList(Node *head, int coeff, int power){
    Node *new = createNode(coeff, power);
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
        printf("%d %d", curr->coefficient, curr->power);
        curr = curr->next;
        if(curr) printf("-->");
    }
    printf("\n");
}

Node *findMiddle(Node *head){
    if (head == NULL) return head;
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        if(fast) slow = slow-> next;
    }
    return slow;
}

Node *merge(Node *left, Node *right){
    if(left == NULL) return right;
    if(right == NULL) return left;

    if(left->power > right->power){
        left->next = merge(left->next, right);
        return left;
    }else if(left->power < right->power){
        right->next = merge(left, right->next);
        return right;
    }else{
        right->coefficient = right->coefficient + left->coefficient;
        right->next = merge(left->next, right-> next);
        return right;
    }
}

Node *mergeSort(Node *head){
    if(head->next == NULL || head == NULL)return head;
    Node *temp = findMiddle(head);
    Node *second =  temp->next;
    temp->next = NULL;

    head = mergeSort(head);
    second = mergeSort(second);

    head = merge(head, second);
    return head;
}

Node *addSortedLists(Node *first, Node *second){
    if(first == NULL)return second;
    if(second == NULL)return first;
    if(first->power > second->power){
        first->next = addSortedLists(first->next, second);
        return first;
    }else if(first->power == second->power){
        first->coefficient = first->coefficient + second->coefficient;
        first->next = addSortedLists(first->next, second->next);
        return first;
    }else{
        second->next = addSortedLists(first, second->next);
        return second;
    }
}

Node *addLists(Node *first, Node *second){
    
    first = mergeSort(first);
    second = mergeSort(second);
    printList(first);
    printList(second);

    first = addSortedLists(first, second);
    return first;
}

void takeInput(){
    int size1;
    Node *head1 = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size1);
    for(int i=0; i<size1; i++){
        int coeff;
        printf("Enter coefficient at index %d of linked list: ", i+1);
        scanf("%d", &coeff);
        int power;
        printf("Enter power at index %d of linked list: ", i+1);
        scanf("%d", &power);
        head1 = createList(head1, coeff, power);
    }
    int size2;
    Node *head2 = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size2);
    for(int i=0; i<size2; i++){
        int coeff;
        printf("Enter coefficient at index %d of linked list: ", i+1);
        scanf("%d", &coeff);
        int power;
        printf("Enter power at index %d of linked list: ", i+1);
        scanf("%d", &power);
        head2 = createList(head2, coeff, power);
    }
    Node *result = addLists(head1, head2);
    // head = deleteNodesWithGreaterRightNodes(head);
    printList(result);
}

int main(){
    takeInput();
    return 0;
}