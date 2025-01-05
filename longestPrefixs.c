#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** readStrings(int* size) {
    printf("Enter the number of strings: ");
    scanf("%d", size);

    if (*size <= 0) {
        printf("No strings to process.\n");
        return NULL;
    }

    char** strings = (char**)malloc((*size) * sizeof(char*));
    if (!strings) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < *size; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char));
        if (!strings[i]) {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    return strings;
}


char* longestCommonPrefix(char** strings, int stringsSize) {
    if (stringsSize == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int minLen = strlen(strings[0]);
    for (int i = 1; i < stringsSize; i++) {
        int len = strlen(strings[i]);
        if (len < minLen) {
            minLen = len;
        }
    }

    char* prefix = (char*)malloc((minLen + 1) * sizeof(char));
    if (!prefix) {
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < minLen; i++) {
        char currentChar = strings[0][i];
        for (int j = 1; j < stringsSize; j++) {
            if (strings[j][i] != currentChar) {
                prefix[index] = '\0';
                return prefix;
            }
        }
        prefix[index++] = currentChar;
    }

    prefix[index] = '\0';
    return prefix;
}


void freeStrings(char** strings, int size) {
    for (int i = 0; i < size; i++) {
        free(strings[i]);
    }
    free(strings);
}

void printPrefix(char** strings, int n) {
    if(strings) {
        char* result = longestCommonPrefix(strings, n);
        if (result) {
            printf("Longest Common Prefix: \"%s\"\n", result);
            free(result);
        }
        freeStrings(strings, n);
    }
}

int main() {
    int n;
    char** strings = readStrings(&n);

    printPrefix(strings, n);

    return 0;
}
