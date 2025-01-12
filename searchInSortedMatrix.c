#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

void takeInput(char *input, int ***arr, int *rows, int *cols) {
    int temp[100][100] = {0};  // Temporary array to store parsed values
    int row = 0, col = 0;

    printf("Enter a 2D array in the format [[1,2,3],[-4,5,6]]:\n");
    scanf("%[^\n]s", input);
    // input = "[[1 4 7 11],[2 5 8 12],[3 6 9 16],[10 13 14 17]]";

    for (char *itr = input; *itr != '\0'; itr++) {
        if (*itr == '[') {
            // Start of a new row
            continue;
        } else if (*itr == '-') {
            // Handle negative numbers
            itr++;
            int number = 0;
            while (*itr >= '0' && *itr <= '9') {
                number = number * 10 + (*itr - '0');
                itr++;
            }
            itr--;
            temp[row][col++] = -number;
            if (col > *cols) *cols = col;
        } else if (*itr >= '0' && *itr <= '9') {
            // Parse positive numbers
            int number = 0;
            while (*itr >= '0' && *itr <= '9') {
                number = number * 10 + (*itr - '0');
                itr++;
            }
            itr--;
            temp[row][col++] = number;
            if (col > *cols) *cols = col;
        } else if (*itr == ']') {
            // End of a row
            if (col > 0) {
                row++;
                col = 0;
            }
        }
    }

    *rows = row;

    // Allocate memory for the 2D array
    *arr = (int **)malloc(*rows * sizeof(int *));
    for (int i = 0; i < *rows; i++) {
        (*arr)[i] = (int *)malloc(*cols * sizeof(int));
        for (int j = 0; j < *cols; j++) {
            (*arr)[i][j] = temp[i][j];
        }
    }
}

void freeArray(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

void findNumber(int **arr, int rows, int cols, int numberToFind){
    int i=0;
    int j=cols-1;
    while(i<rows && j>=0){
        if(arr[i][j] > numberToFind){
            j--;
        }else if(arr[i][j] < numberToFind){
            i++;
        }else{
            printf("The number %d is found at %d, %d", numberToFind, i+1, j+1);
            return;
        }
    }
    printf("Number doesn't exist in matrix");
}

int main() {
    int rows = 0, cols = 0;
    int numberToFind = 0;
    char *input = (char *)malloc(1000 * sizeof(char));  // Allocate a larger buffer
    int **arr;

    takeInput(input, &arr, &rows, &cols);
    scanf("%d", &numberToFind);


    findNumber( arr, rows, cols, numberToFind);

    freeArray(arr, rows);
    free(input);

    return 0;
}
