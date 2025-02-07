#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int key;
    int value;
    struct Node *next;
}Node;

typedef struct hashMap{
    int capacity;
    Node **arr; 
}hashMap;

Node *createNode(int key, int value){
    Node *new = (Node *)malloc(sizeof(Node));
    new->key = key;
    new->value = value;
    new->next = NULL;
    return new;
}

void initializeHashMap(hashMap *map, int capacity){
    map->capacity = capacity;
    map->arr = (Node **)calloc(map->capacity, sizeof(Node *));
    return;
}

int hashFunction(hashMap *map, int key){
    int bucketIndex = key % map->capacity;
    return bucketIndex;
}

void insert(hashMap *map, int key, int value){
    int bucketIndex = hashFunction(map, key);
    Node *new = createNode(key, value);

    if(map->arr[bucketIndex] == NULL){
        map->arr[bucketIndex] = new;
    }else{
        new->next = map->arr[bucketIndex];
        map->arr[bucketIndex] = new;
    }
    return;
}

void delete(hashMap *map, int key){
    int bucketIndex = hashFunction(map, key);
    Node *currNode = map->arr[bucketIndex];
    Node *prevNode = NULL;
    while(currNode){
        if(key == currNode->key){
            if(currNode == map->arr[bucketIndex]){
                map->arr[bucketIndex] = currNode->next;
            }else{
                prevNode->next = currNode->next;
            }
            printf("Deleting key: %d, value %d\n", currNode->key, currNode->value);
            free(currNode);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    printf("Invalid Key\n");
    return;
}

void search(hashMap *map, int key){
    int bucketIndex = hashFunction(map, key);

    Node *bucketHead = map->arr[bucketIndex];
    while(bucketHead){
        if(bucketHead->key == key){
            printf("Value: %d\n", bucketHead->value);
            return;
        }
        bucketHead = bucketHead->next;
    }
    printf("Invalid key\n");
}

void printMap(hashMap *map){
    for(int i=0; i<map->capacity; i++){
        if(map->arr[i]){
            Node *ptr = map->arr[i];
            printf("Index %d: ", i);
            while(ptr){
                printf("(%d, %d)", ptr->key, ptr->value);
                ptr = ptr->next;
                if(ptr) printf("->");
                else printf("\n");
            }
        }
    }
    return;
}

void takeInput(){
    hashMap *map = (hashMap *)malloc(sizeof(hashMap));
    initializeHashMap(map, 10);
    while(1){
        int operation;
        printf("Enter 1 to insert, 2 to search, 3 to delete, 4 to display and 5 to exit: ");
        scanf("%d", &operation);
        if(operation == 5){
            break;
        }
        int key;
        switch (operation)
        {
        case 1:
            int value;
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(map, key, value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            search(map, key);
            break;
        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            delete(map, key);
            break;
        case 4:
            printMap(map);
            break;
        default:
            break;
        }
    }
    
}

int main(){
    takeInput();
    return 0;
}