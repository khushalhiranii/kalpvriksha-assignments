#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

void takeInput(char *input, int ***arr, int *rows, int *cols) {
    int temp[100][100] = {0};
    int row = 0, col = 0;

    printf("Enter a 2D array in the format [[1,2,3],[-4,5,6]]:\n");
    scanf("%[^\n]s", input);
    // input = "[[ 1, 5, 7, 9, 11 ],[ 2, 3, 4, 8, 12 ],[ 4, 11, 14, 19, 20 ],[ 6, 10, 22, 99, 100 ],[ 7, 15, 17, 24, 28 ]]";

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

bool isPeak(int** mat, int row, int col, int matSize, int matColSize){
    if( row-1>=0 && mat[row-1][col] > mat[row][col] ) return false;
    if( row+1<matSize && mat[row+1][col] > mat[row][col] ) return false;
    if( col-1>=0 && mat[row][col-1] > mat[row][col] ) return false;
    if( col+1<matColSize && mat[row][col+1] > mat[row][col] ) return false;
    return true;
}

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize) {
    int index=0;
    int *ans = (int *)malloc(2 * sizeof(int));
    int found=0;
    for(int i=0; i<matSize; i++){
        if(found){
            break;
        }
        for(int j=0; j<(*matColSize); j++){
            if(isPeak(mat, i, j, matSize, *matColSize)){
                ans[0] = i;
                ans[1] = j;
                found = 1;
                break;
            };

        }
    }
    *returnSize = 2;
    return ans;

}
void printIndex(int *ans, int *returnSize){
    for(int i=0; i<(*returnSize); i++){
        printf("%d ", ans[i]);
    }
}


int main() {
    int rows = 0, cols = 0;
    int numberToFind = 0;
    char *input = (char *)malloc(1000 * sizeof(char));
    int **arr;

    takeInput(input, &arr, &rows, &cols);

    int returnSize;
    int *ans = findPeakGrid( arr, rows, &cols, &returnSize);
    printIndex( ans, &returnSize);

    freeArray(arr, rows);
    free(input);

    return 0;
}
