#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

void takeInput(char *input, int ***arr, int *rows, int *cols) {
    int temp[100][100] = {0};
    int row = 0, col = 0;

    printf("Enter a 2D array in the format [[1,2,3],[-4,5,6]]:\n");
    // scanf("%[^\n]s", input);
    input = "[[1 4 7 11],[2 5 8 12],[3 6 9 16],[10 13 14 17]]";

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

int sum(int** grid, int gridSize, int gridColSize, int row, int col) {
    if (row >= gridSize || col >= gridColSize) return INT_MAX;

    if (row == gridSize - 1 && col == gridColSize - 1){
        return grid[row][col];
    }

    int right = sum(grid, gridSize, gridColSize, row, col + 1);

    int bottom = sum(grid, gridSize, gridColSize, row + 1, col);

    return grid[row][col] + (right < bottom ? right : bottom);
}

int main() {
    int rows = 0, cols = 0;
    char *input = (char *)malloc(1000 * sizeof(char));
    int **arr;

    takeInput(input, &arr, &rows, &cols);


    int minSumPath = sum( arr, rows, cols, 0, 0);
    printf("%d", minSumPath);

    freeArray(arr, rows);
    free(input);

    return 0;
}
