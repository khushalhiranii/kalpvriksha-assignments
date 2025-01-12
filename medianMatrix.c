#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

void takeInput(char *input, int ***arr, int *rows, int *cols) {
    int temp[100][100] = {0};
    int row = 0, col = 0;

    printf("Enter a 2D array in the format [[1,2,3],[-4,5,6]]:\n");
    scanf("%[^\n]s", input);
    // input = "[[ 1, 5, 7, 9, 11 ],[ 2, 3, 4, 8, 9 ],[ 4, 11, 14, 19, 20 ],[ 6, 10, 22, 99, 100 ],[ 7, 15, 17, 24, 28 ]]";

    for (char *itr = input; *itr != '\0'; itr++) {
        if (*itr == '[') {
            continue;
        } else if (*itr == '-') {
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
            int number = 0;
            while (*itr >= '0' && *itr <= '9') {
                number = number * 10 + (*itr - '0');
                itr++;
            }
            itr--;
            temp[row][col++] = number;
            if (col > *cols) *cols = col;
        } else if (*itr == ']') {
            if (col > 0) {
                row++;
                col = 0;
            }
        }
    }

    *rows = row;

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

void sortMatrix(int **arr, int rows, int cols){
    for(int i=0;i<rows;i++){   
        for(int j=0;j<cols;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    int *flatArr = (int *)malloc(rows* cols * sizeof(int));
    int index = 0;
    for(int i=0; i<rows; i++){
        for(int j=0;j<cols;j++){
            flatArr[index] = arr[i][j];
            index++;
        }
    }
    for(int i=0; i<index; i++){
        for(int j=i+1; j<index; j++){
            if(flatArr[i] > flatArr[j] ){
                int temp = flatArr[i];
                flatArr[i] = flatArr[j];
                flatArr[j] = temp;
            }
        }
    }
    int median = (index-1)/2;
    printf("%d", flatArr[median]);
}

int main() {
    int rows = 0, cols = 0;
    int numberToFind = 0;
    char *input = (char *)malloc(1000 * sizeof(char));  // Allocate a larger buffer
    int **arr;

    takeInput(input, &arr, &rows, &cols);
    // scanf("%d", &numberToFind);


    sortMatrix( arr, rows, cols);

    freeArray(arr, rows);
    free(input);

    return 0;
}
