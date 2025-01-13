#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ifExist(char *unique, char ch) {
    for (int i = 0; unique[i] != '\0'; i++) {
        if (unique[i] == ch) {
            return i;
        }
    }
    return -1;
}

char *uniqueCharacters(char *s) {
    int size = strlen(s);
    char *unique = (char *)malloc((size + 1) * sizeof(char));
    int index = 0;
    unique[index] = s[0];
    index++;
    for (int i = 1; i < size; i++) {
        int idx = ifExist(unique, s[i]);
        if (idx == -1) {
            unique[index] = s[i];
            index++;
        }
    }
    unique[index] = '\0';
    return unique;
}

void countFrequency(char *s, int *freq) {
    int size = strlen(s);
    for (int i = 0; i < size; i++) {
        freq[s[i]]++;
    }
}

void sortByFrequency(char *unique, int *freq) {
    int size = strlen(unique);
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (freq[unique[i]] < freq[unique[j]]) {
                char tempChar = unique[i];
                unique[i] = unique[j];
                unique[j] = tempChar;
            }
        }
    }
}

char *constructOutput(char *unique, int *freq) {
    int size = 0;
    for (int i = 0; unique[i] != '\0'; i++) {
        size += freq[unique[i]];
    }
    char *output = (char *)malloc((size + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; unique[i] != '\0'; i++) {
        for (int j = 0; j < freq[unique[i]]; j++) {
            output[index++] = unique[i];
        }
    }
    output[index] = '\0';
    return output;
}

int main() {
    char s[100];
    scanf("%s", s);
    int freq[256] = {0};

    char *unique = uniqueCharacters(s);
    countFrequency(s, freq);
    sortByFrequency(unique, freq);
    char *output = constructOutput(unique, freq);

    printf("Sorted by frequency: %s\n", output);

    free(unique);
    free(output);

    return 0;
}