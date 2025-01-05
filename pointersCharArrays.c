#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char vowelToConsonant(char ch) {
    char vowels[] = "aeiou";
    char consonants[] = "bcdfg";
    for (int i = 0; i < 5; i++) {
        if (ch == vowels[i]) {
            return consonants[i];
        }
    }
    return ch;
}

void replaceVowelsWithRespectiveConsonants(char *input) {
    for (int i = 0; i < strlen(input); i++) {
        input[i] = vowelToConsonant(input[i]);
    }
    printf("%s", input);
}

void readInput(char *input) {
    if(input == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    scanf("%[^\n]", input);
}

int main() {
    char *input = (char *)malloc(1000 * sizeof(char));
    
    readInput(input);

    replaceVowelsWithRespectiveConsonants(input);
    free(input);
    return 0;
}