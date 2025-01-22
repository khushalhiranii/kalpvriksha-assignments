#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

void printArray(int **ans, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}

void fillAdjacent(int** image, int imageSize, int imageColSize, int sr, int sc, int color, int prevColor){
    if(sr<0 || sc<0 || sr>=imageSize || sc>=imageColSize || image[sr][sc] != prevColor) return;
    
    image[sr][sc] = color;

    fillAdjacent(image, imageSize, imageColSize, sr+1, sc, color, prevColor);
    fillAdjacent(image, imageSize, imageColSize, sr-1, sc, color, prevColor);
    fillAdjacent(image, imageSize, imageColSize, sr, sc+1, color, prevColor);
    fillAdjacent(image, imageSize, imageColSize, sr, sc-1, color, prevColor);
 }
int** floodFill(int** image, int imageSize, int imageColSize, int sr, int sc, int color) {
    int prevColor = image[sr][sc];
    if(prevColor != color){
        fillAdjacent(image, imageSize, imageColSize, sr, sc, color, prevColor);
    }
    return image;
}

void takeInput(char *input, int ***arr, int *rows, int *cols) {
    int temp[100][100] = {0};
    int row = 0, col = 0;

    printf("Enter a 2D array in the format [[1,2,3],[-4,5,6]]:\n");
    scanf("%[^\n]s", input);
    // input = "[[1 4 7 11],[2 5 8 12],[3 6 9 16],[10 13 14 17]]";

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

    int sr, sc, color;

    printf("Enter index to change: ");
    scanf("%d %d", &sr, &sc);
    printf("Enter color: ");
    scanf("%d", &color);
    int **ans = floodFill(*arr, *rows, *cols, sr, sc, color);
    printArray(ans, *rows, *cols);
}

void freeArray(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int rows = 0, cols = 0;
    char *input = (char *)malloc(1000 * sizeof(char));
    int **arr;

    takeInput(input, &arr, &rows, &cols);


    

    freeArray(arr, rows);
    free(input);

    return 0;
}
