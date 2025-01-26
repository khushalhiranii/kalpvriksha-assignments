#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool isAnagram(char* string, char* input){
    int frequency[26] = {0};
    if(strlen(string) != strlen(input)){
        return false;
    }
    while(*string != '\0'){
        frequency[(*string)-'a']++;
        string++;
    }
    while(*input != '\0'){
        if(frequency[(*input)-'a'] == 0) return false;
        frequency[(*input)-'a']--;
        input++;
    }
    return true;
 }
void groupAnagrams(char** strs, int strsSize) {

    int visited[strsSize];
    for(int i=0; i<strsSize; i++) visited[i]=0;
    for(int i=0; i<strsSize; i++){
        if(visited[i] ==1) continue;
        for(int j=i+1; j<strsSize; j++){
            if(visited[j] ==1) continue;
            if(isAnagram(strs[i], strs[j])){
                visited[j]=1;
                printf("%s ", strs[j]);
            }
        }
        printf("%s ", strs[i]);
    }
}

void takeInput(){
    int size;
    printf("Enter number of strings: ");
    scanf("%d", &size);
    char **arr = (char **)malloc(size * sizeof(char *));
    for(int i=0; i<size; i++){
        arr[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter string position %d: ", i+1);
        scanf("%s", arr[i]);
    }
    groupAnagrams(arr, size);
    
}

int main(){
    takeInput();
}