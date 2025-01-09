#include <stdio.h>
#include<string.h>

void alphabetFrequency(char arr[], char ans[]){
    int lastWord = 0;
    for(int i=0; i<strlen(arr); i++){
        int found=0;
        for(int j=0; j<strlen(ans); j+=2){
            if(arr[i] == ans[j]){
                found=1;
                ans[j+1] += 1;
            }
        }
        if(!found){
            ans[lastWord] = arr[i];
            ans[lastWord+1] = 1+'0';
            lastWord+=2;
        }
    }
}

int main()
{
    char arr[100];
    char ans[300];
    scanf("%s", arr);
    
    alphabetFrequency(arr, ans);
    printf("%s", ans);
    return 0;
}
