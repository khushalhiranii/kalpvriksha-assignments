#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *input, int a, int b ){
    char temp = input[a];
    input[a] = input[b];
    input[b] = temp;
}

void permutations(char input[], int index){
    int size = strlen(input);
    if(index == size-1){
        printf("%s \n", input);
    }
    for(int i=index; i<size; i++){
        swap(input, index, i);
        permutations(input, index+1);
        swap(input, index, i);
    }
}

int main(){
    char input[100];
    scanf("%s", input);
    permutations(input, 0);
}