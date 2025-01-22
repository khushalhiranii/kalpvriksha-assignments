#include<stdio.h>
#include<string.h>
#include<math.h>

int titleToNumber(char* columnTitle) {
    int size = strlen(columnTitle);
    int ans=0;
    for(int i=size-1; i>=0; i--){
        ans += pow(26, size-1-i) * (columnTitle[i] - 'A' + 1);
    }
    return ans;
}

void takeInput(){
    char string[100];
    printf("Enter title in Upper casse: ");
    scanf("%s", string);
    int ans = titleToNumber(string);
    printf("%d", ans);
}

int main(){
    takeInput();
}