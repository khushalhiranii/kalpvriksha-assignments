#include <stdio.h>
#include <stdlib.h>

void inputWithValidations(int *rows, int *cols) {
    int valid;

    do {
        printf("Rows: ");
        valid = scanf("%d", rows);
        while (getchar() != '\n');
        if (valid != 1 || *rows <= 0) {
            printf("Invalid input. Rows must be a positive integer.\n");
        }
    } while (valid != 1 || *rows <= 0);

    do {
        printf("Cols: ");
        valid = scanf("%d", cols);
        while (getchar() != '\n'); 
        if (valid != 1 || *cols <= 0) {
            printf("Invalid input. Cols must be a positive integer.\n");
        }
    } while (valid != 1 || *cols <= 0);
}

void takeInputforDynamicallyAllocatedArray(int **arr, int rows, int cols) {
    int valid;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            do{
                printf("Enter element at index %d %d: ", i, j);
                valid = scanf("%d", &arr[i][j]);
                while (getchar() != '\n');
                if (valid != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                }
            }while(valid != 1);
        }
    }
}

void printDynamicallyAllocatedArray(int **arr, int rows, int cols) {
    int least = rows < cols ? rows : cols;
    for (int i = 0; i < least; i++) {
        printf("%d ", arr[i][i]);
        printf("\n");        
    }
}

void dynamicallyAllocateMemory(int rows, int cols) {
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    takeInputforDynamicallyAllocatedArray(arr, rows, cols);
    printDynamicallyAllocatedArray(arr, rows, cols);

    
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int rows, cols;
    inputWithValidations(&rows, &cols);
    dynamicallyAllocateMemory(rows, cols);
    return 0;
}