#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char str[], int start, int end){
    while(start<end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void longestPalindrome(char str[], char ans[]){
    int maxLen = 0;
    int start=0;
    int len=strlen(str); 
    for(int i=0; i<len; i++){
        for(int j=len-1; j>i; j--){
            if((j-i+1)>maxLen && isPalindrome(str, i, j)){
                maxLen = j-i+1;
                start = i;
            }
        }
    }
    for(int i=0; i<maxLen; i++){
        ans[i] = str[start+i];
    }
    ans[maxLen] = '\0';

}

int main(){
    char str[100];
    char ans[100];
    scanf("%s", str);
    
    longestPalindrome(str, ans);

    if(strlen(ans)>0){
        printf("%s", ans);
    }else{
        printf("No palindrome");
    }
}