#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* removeOuterParentheses(char* s) {

    int size =strlen(s); 
    int count  = 0;
    char *ans = (char *)malloc((size)*sizeof(char));
    int index = 0;

    for(int i=0;i<size;i++){
        if(s[i]=='(')count++;
        else if(s[i]==')')count--;

        if(count==0){
            i++;
            count=1;
            continue;
        }else{
            ans[index++] = s[i];
        }
    }
    ans[index]='\0';


    ans++;
    return ans;
}

void takeInput(char *input1){
    printf("Enter string in the format - (()(()())): ");
    scanf("%s", input1);
    char *ans = removeOuterParentheses(input1);
    printf("%s", ans);
}

int main(){
    char *input1 = (char *)malloc(50 * sizeof(char));
    takeInput(input1);
}