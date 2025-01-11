#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isSimilar(char test[], char string[], int start){
    for(int i=0; i<(strlen(string)/2); i++){
        if(test[i] == string[start+i])continue;
        else return false;
    }
    return true;
}

int main(){
    char string[100];
    char test[100];
    scanf("%s", string);
    scanf("%s", test);
    char s[200];
    for(int i=0; i<2*strlen(string); i++){
        int charAt=i%(strlen(string));
        s[i] = string[charAt];
    }
    s[2*strlen(string)] = '\0';
    // printf("%s", s);
    bool presence = false;
    for(int i=0; i<strlen(s); i++){
        presence = isSimilar( test, s, i);
        if (presence== true) break;
    }
    if (presence== true) printf("True");
    else printf("false");
}