#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

Node* bubbleSort(Node* head) {
    Node* ptr;
    int swapped = 1;
    Node* tail = NULL;
    while (swapped) {
        ptr = head;
        swapped = 0;
        while (ptr && ptr->next != tail) {
            if (ptr->data > ptr->next->data) {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        tail = ptr;
    }
    return head;
}

Node* createNode(int value) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
    return new;
}

Node* createList(Node* head, int value) {
    Node* new = createNode(value);
    if (head == NULL) {
        head = new;
    } else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

Node* split(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        if (fast) slow = slow->next;
    }
    Node* secondHalf = slow->next;
    slow->next = NULL;
    return secondHalf;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next_ = NULL;

    while (curr) {
        next_ = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_;
    }
    return prev;
}

Node* mergeAlternatively(Node* first, Node* second) {
    Node* firstPtr = first;
    Node* secondPtr = second;

    while (firstPtr && secondPtr) {
        Node* tempFirst = firstPtr->next;
        Node* tempSecond = secondPtr->next;

        firstPtr->next = secondPtr;
        secondPtr->next = tempFirst;

        firstPtr = tempFirst;
        secondPtr = tempSecond;
    }
    return first;
}

Node* alternateSort(Node* head) {
    Node* first = bubbleSort(head);
    Node* second = split(first);
    second = reverseLinkedList(second);
    return mergeAlternatively(first, second);
}

void inputForList(int size) {
    int first;
    printf("Enter 1 element: ");
    scanf("%d", &first);
    Node* head = createNode(first);
    for (int i = 1; i < size; i++) {
        int data;
        printf("Enter %d element: ", i + 1);
        scanf("%d", &data);
        head = createList(head, data);
    }

    printf("Original List: ");
    printList(head);

    head = alternateSort(head);

    printf("Alternatively Sorted List: ");
    printList(head);
}

void takeInput() {
    int size;
    printf("Enter size of Linked List: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid input\n");
        return;
    }

    inputForList(size);
}

int main() {
    takeInput();
    return 0;
}
