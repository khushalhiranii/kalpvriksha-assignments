#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printFinalString(int *visited, char input[]){
    for(int j=0; j<strlen(input); j++){
        if((visited[input[j]-'a']) == 1){
            printf("%c", input[j]);
        }else{
            visited[input[j]-'a'] -= 1;
        }
    }
    
}

void removeDuplicates(int *visited, char input[]){
    for(int i=0; i<26; i++){
        if((visited[i]%2) == 0){
            visited[i] = 0;
        }
    }
    printFinalString(visited, input);
}

void markVisited(char input[]){
    int visited[26] = {0};
    scanf("%s", input);

    for(int i=0; i<strlen(input); i++){
        visited[input[i]-'a'] += 1;
    }
    removeDuplicates(visited, input);
}

int main(){
    
    char input[100];
    markVisited(input);

}