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
    return;
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

Node *findNode(Node *head, int power){
    printf("Power: %d", power);
    if(head == NULL) return head;
    printList(head);
    Node *ptr = head;
    while(ptr){
        if(ptr->power == power) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Node *multiplyLists(Node *first, Node *second){
    printList(first);
    printList(second);
    Node *ans = NULL;
    Node *ptr1 = first;
    Node *ptr2 = second;

    while(ptr1){
        ptr2 = second;
        while(ptr2){
            Node *existing = NULL;
            int coeff = ptr1->coefficient * ptr2->coefficient;
            int power = ptr1->power + ptr2->power;
            existing = findNode(ans, power);
            if(existing != NULL){
                printf("Yes exist: %d %d\n", existing->coefficient, existing->power);
                existing->coefficient += coeff;
            }else{
                ans = createList(ans, coeff, power);
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    
    ans = mergeSort(ans);
    return ans;
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
    Node *result = multiplyLists(head1, head2);
    // head = deleteNodesWithGreaterRightNodes(head);
    printList(result);
}

int main(){
    takeInput();
    return 0;
}