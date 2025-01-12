#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isIsomorphic(char* s, char* t) {
    if(strlen(s) != strlen(t))return false;
    char visited[256] = {0};
    
    for(int i=0; i<strlen(s); i++){
        if(visited[s[i]] != 0){
            if(t[i] != visited[s[i]]){
                return false;
            }
        }else{
            for(int j=0; j<256; j++){
                if(visited[j] == t[i])return false;
            }
            visited[s[i]] = t[i];
        }
    }
    return true;

}
void takeInput(char *input1, char *input2){
    printf("Enter first string: ");
    scanf("%s", input1);
    printf("Enter second string: ");
    scanf("%s", input2);
    bool isomorphic = isIsomorphic(input1, input2);
    if(isomorphic){
        printf("Strings are isomorphic");
    }else{
        printf("Strings are not isomorphic");
    }
}

int main(){
    char *input1 = (char *)malloc(50 * sizeof(char));
    char *input2 = (char *)malloc(50 * sizeof(char));
    takeInput(input1, input2);
}