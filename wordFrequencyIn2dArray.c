#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct fruit{
    char *name;
    int freq;
}fruit;

fruit *cart[100];

void takeFruitsIn2dArray(char ***fruits, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("\nEnter fruit at %d, %d: ", i, j);
            scanf("%s", fruits[i][j]);
        }
    }
    
}

int compareString(char *query, char *string){
    if((*query) == '\0' && (*string) == '\0' ){
        return 1;
    }else if((*query) == (*string)){
        return compareString(++query, ++string);
    }
    
    return 0;
    
}

void updateIfExist(char *newFruit, int *size){
    int found = 0;
    for(int i=0; i<(*size); i++){
        // printf("%s %s", newFruit, cart[i]->name);
        if(compareString(newFruit, cart[i]->name)){
            cart[i]->freq += 1;
            // printf("%s %d\n", cart[i]->name, cart[i]->freq);
            found=1;
        }
    }
    if(!found){
        fruit *obj = (fruit *)malloc(sizeof(fruit));
        obj->name = (char *)malloc(50 * sizeof(char));
        obj->name = newFruit;
        obj->freq = 1;
        cart[*size] = obj;
        (*size)++;
    }
}

void frequencyOfFruits(char ***fruits, int rows, int columns){
    int unqFruits=0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            updateIfExist(fruits[i][j], &unqFruits);
        }
    }
    for(int i=0; i<unqFruits; i++){
        printf("%s %d\n", cart[i]->name, cart[i]->freq);
    }
}





int main(){
    int rows, columns = 0;
    printf("Rows: ");
    scanf("%d", &rows);
    printf("Columns: ");
    scanf("%d", &columns);
    char ***fruits = (char ***)malloc(rows * sizeof(char **));
    for(int i=0; i<rows; i++){
        fruits[i] = (char **)malloc(columns * sizeof(char *));
        for(int j=0; j<columns; j++){
            fruits[i][j] = (char *)malloc(30 * sizeof(char));
        }
    }
    takeFruitsIn2dArray(fruits, rows, columns);
    frequencyOfFruits(fruits, rows, columns);
    return 0;
}
