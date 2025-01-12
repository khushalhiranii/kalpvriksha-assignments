#include <stdio.h>
#include <stdlib.h>

void inputToArray(int *arr, char *input, int *size) {
    *size = 0;
    while (*input != '\0') {
        if (*input == '[' || *input == ' ' || *input == ',') {
            input++;
            continue;
        }
        int negative = 0;
        if (*input == '-') {
            negative = 1;
            input++;
        }
        int number = 0;
        while ((*input >= '0' && *input <= '9')) {
            number = (number * 10) + (*input - '0');
            input++;
        }
        if (negative) {
            number = -number;
        }
        arr[(*size)++] = number;
        if (*input == ']' || *input == ',' ) {
            input++;
        }
    }
}

int maxSum(int *arr, int size){
    int maxSum = arr[0];
    int currSum = 0;
    int i=0;
    while(i<size){
        currSum += arr[i];
        if(currSum>maxSum)maxSum=currSum;
        if(currSum<0)currSum=0;
        i++;
    }
    return maxSum;
}

int main() {
    char *input = (char *)malloc(100 * sizeof(char));
    int *arr = (int *)malloc(100 * sizeof(int));
    int size = 0;
    scanf("%[^\n]s", input);

    inputToArray(arr, input, &size);

    int max = maxSum(arr, size);
    printf("%d", max);

    return 0;
}