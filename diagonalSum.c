#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

void takeInput(char *input, int ***arr, int *rows, int *cols) {
    int temp[100][100] = {0};  // Temporary array to store parsed values
    int row = 0, col = 0;

    printf("Enter a 2D array in the format [[1 2 3],[-4 5 6]]:\n");
    scanf("%[^\n]s", input);
    // input = "[[1,10,4],[9,3,8],[15,16,17]]";

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
            // End of a row
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

int diagonalSum(int **arr, int rows, int cols){
    int sum=0;
    for(int i=0; i<rows; i++){
        
        sum = sum + arr[i][i] + arr[i][cols-i-1];
    }
    if(rows%2==1){
        int in = rows/2;
        sum = sum - arr[in][in];
    }
    return sum;
}

int main() {
    int rows = 0, cols = 0;
    char *input = (char *)malloc(1000 * sizeof(char));  // Allocate a larger buffer
    int **arr;

    takeInput(input, &arr, &rows, &cols);


    int diagonal = diagonalSum( arr, rows, cols);
    printf("%d", diagonal);

    freeArray(arr, rows);
    free(input);

    return 0;
}
