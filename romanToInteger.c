#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int romanValue(char *input){
    switch(*input){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

void evaluate(char *input){
    char *itr = input;
    int ans=0;
    while( *itr != '\0' ){
        if(romanValue(itr) == -1){
            printf("Invalid input");
            return;
        }
        if(romanValue(itr)<romanValue(itr+1)){
            ans += romanValue(itr)*(-1);
        }else{
            ans += romanValue(itr);
        }
        itr++;
    }
    printf("%d", ans);
}

int main()
{
    char *input = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]s", input);
    getchar();
    evaluate(input);
    // printf("%d", value);
    return 0;
}
