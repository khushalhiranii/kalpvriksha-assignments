#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void takeInput(char *input, int ***arr, int *rows, int *cols) {
    int temp[100][100] = {0};  // Temporary array to store parsed values
    int row = 0, col = 0;

    printf("Enter a 2D array in the format [[1 2 3],[-4 5 6]]:\n");
    scanf("%[^\n]s", input);
    // input = "[[1,10,4,2],[9,3,8,7],[15,16,17,12]]";

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

int minsAndMaxs(int **arr, int rows, int cols){
    for(int i=0; i<rows; i++){
        int minRow = arr[i][0];
        int minColIndex = 0;
        for(int j =1; j<cols; j++){
            if(arr[i][j]<minRow){
                minRow=arr[i][j];
                minColIndex=j;
            }
        }

        int k;
        for(k=0; k<rows; k++){
            if(arr[k][minColIndex]>minRow) break;
        }
        if(k == rows){
            return minRow;
        }

    }
    return -1;
}

int main() {
    int rows = 0, cols = 0;
    char *input = (char *)malloc(1000 * sizeof(char));  // Allocate a larger buffer
    int **arr;

    takeInput(input, &arr, &rows, &cols);


    int saddle = minsAndMaxs( arr, rows, cols);
    printf("%d", saddle);

    freeArray(arr, rows);
    free(input);

    return 0;
}
