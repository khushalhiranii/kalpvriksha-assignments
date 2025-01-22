#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool search(char** board, int boardSize, int boardColSize, const char* word, int index, int row, int col, bool** visited) {
    if (index == strlen(word)) return true;

    if (row < 0 || row >= boardSize || col < 0 || col >= boardColSize || visited[row][col] || board[row][col] != word[index]) {
        return false;
    }

    visited[row][col] = true;

    bool found = search(board, boardSize, boardColSize, word, index + 1, row - 1, col, visited) ||
                 search(board, boardSize, boardColSize, word, index + 1, row + 1, col, visited) ||
                 search(board, boardSize, boardColSize, word, index + 1, row, col - 1, visited) ||
                 search(board, boardSize, boardColSize, word, index + 1, row, col + 1, visited);

    visited[row][col] = false;

    return found;
}

bool exist(char** board, int boardSize, int boardColSize, const char* word) {
    bool** visited = (bool**)malloc(boardSize * sizeof(bool*));
    for (int i = 0; i < boardSize; i++) {
        visited[i] = (bool*)calloc(boardColSize, sizeof(bool));
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (search(board, boardSize, boardColSize, word, 0, i, j, visited)) {
                return true;
            }
        }
    }

    for (int i = 0; i < boardSize; i++) {
        free(visited[i]);
    }
    free(visited);

    return false;
}

void takeInput(char *input, char ***board, int *rows, int *cols) {
    char temp[100][100];
    char word[100];
    int row = 0, col = 0, maxCol = 0;

    printf("Enter a 2D array:\n");
    scanf(" %[^\n]s", input);
    printf("Word to search: ");
    scanf("%s", word);

    for (char *itr = input; *itr != '\0'; itr++) {
        if (*itr == '[') {
            continue;
        } else if ((*itr >= 'A' && *itr <= 'Z') || (*itr >= 'a' && *itr <= 'z')) {
            temp[row][col++] = *itr;
            if (col > maxCol) maxCol = col;
        } else if (*itr == ']') {
            if (col > 0) {
                row++;
                col = 0;
            }
        }
    }

    *rows = row;
    *cols = maxCol;

    *board = (char **)malloc(*rows * sizeof(char *));
    for (int i = 0; i < *rows; i++) {
        (*board)[i] = (char *)malloc(*cols * sizeof(char));
        for (int j = 0; j < *cols; j++) {
            (*board)[i][j] = temp[i][j];
        }
    }

    bool searchWord = exist(*board, *rows, *cols, word);
    printf("%d", searchWord);
}

void freeArray(char **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}




int main() {
    int rows = 0, cols = 0;
    char *input = (char *)malloc(1000 * sizeof(char));
    char **board;

    takeInput(input, &board, &rows, &cols);

    freeArray(board, rows);
    free(input);

    return 0;
}
