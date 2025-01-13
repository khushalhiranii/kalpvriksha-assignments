#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

bool presence(char *string, int start, int end, int test_freq[], int totalWords){
    int temp_freq[256] ={0};
    for(int i=0; i<256; i++){
        temp_freq[i]=test_freq[i];
    }
    int matched_words = 0;
    for(int i=start; i<=end; i++){
        // printf("%c", string[i]);
        int index=string[i];
        if(temp_freq[index]>0){
            
            temp_freq[index]--;
            matched_words++;
        }
        // printf("\n");
    }
    return matched_words == totalWords;
    
}

void smallestSubstring(char *string, char *test, int *test_freq, int totalWords){
    int words = totalWords;
    int minLength = INT_MAX;
    int start = 0;
    int end = 0;
    for(int i=0; i<strlen(string); i++){
        for(int j=i; j<strlen(string); j++){
            if((j-i+1)<minLength && presence(string, i, j, test_freq, words)){
                minLength=j-i+1;
                start=i;
                // printf("\n%d %d", start, j);
                end = j;
            }
        }
    }
    if(minLength!=INT_MAX){
        for(int i=start; i<=end; i++){
            printf("%c", string[i]);
        }
    }
    // for(int i=start;i<=end;i++){
        // printf("%s", string+start);
    // }
}

void takeInput(char *string, char *test, int *test_freq){
    printf("Enter input string: ");
    scanf("%[^\n]s", string);
    getchar();
    printf("\nEnter test string: ");
    scanf("%[^\n]s", test);
    int totalWords=0;
    for(int i=0; i<strlen(test); i++){
        int index=test[i];
        test_freq[index]++;
        totalWords++;
    }
    // printf("%d\n", totalWords);
    smallestSubstring(string, test, test_freq, totalWords);
}

int main()
{
    char *string = (char *)malloc(100 * sizeof(char));
    char *test = (char *)malloc(100 * sizeof(char));
    int test_freq[256] = {0};
    takeInput(string, test, test_freq);

    return 0;
}
