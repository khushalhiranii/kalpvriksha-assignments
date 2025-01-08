#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void checkVowel( char *ch, int *vowelCount) {
    char vowels[] = "aeiou";
    for (int i = 0; i < 5; i++) {
        if (ch[0] == vowels[i] || ch[0] == vowels[i]-32) {
            (*vowelCount)++;
        }
    }
}
void updateLongestWord(char *ch, int *wordCount, char **ans, int *index){
    char *itr = ch;
    int length = 0;
    while(*itr != '\0'){
        itr++;
        length++;
    }
    if(length> *wordCount){
        *index = 0;
        ans[*index] = ch;
        (*index)++;
        *wordCount = length;
    }else if(length == *wordCount){
        ans[*index] = ch;
        (*index)++;
    }
}


void dynamicallyAllocate3dArray(int rows, int columns, int *wordCount, int *index,int *vowelCount){
    char **ans = (char **)malloc(100 * sizeof(char *)) ;
    
    for(int i=0; i<100; i++){
        ans[i]=(char *)malloc(100 * sizeof(char));
    }
    
    char ***arr = (char ***)malloc(rows * sizeof(char **)) ;
    
    for(int i=0; i<rows ; i++){
        arr[i]=(char **)malloc(columns * sizeof(char *));
        for(int j=0; j<columns; j++){
            arr[i][j] = (char *)malloc(100 * sizeof(char));
            printf("Name at index %d %d: ", i, j);
            scanf("%s", arr[i][j]);
            while (getchar() != '\n');
            checkVowel(arr[i][j], vowelCount);
            updateLongestWord(arr[i][j], wordCount, ans, index);
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%s ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Number of strings starting with vowels are %d", *vowelCount);
    for(int i=0; i<(*index); i++){
        printf("\n%s ", ans[i]);
    }
}

int main()

{
    int rows, columns = 0;
    int vowelCount=0;
    int wordCount=0;
    int index=0;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);
    
    dynamicallyAllocate3dArray(rows, columns, &wordCount, &index, &vowelCount);
    
    

    return 0;
}
