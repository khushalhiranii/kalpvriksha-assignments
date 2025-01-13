#include<stdio.h>
#include<stdlib.h>

int** generate(int numRows) {
    int **ans = (int **)malloc(numRows * sizeof(int *));
    for(int i=0; i<numRows; i++){
        ans[i] = (int *)malloc((i+1) * sizeof(int));
    }
    for(int i=0; i<numRows; i++){
        ans[i][0]=1;
        ans[i][i]=1;
        if(i>=2){
            for(int j=1; j<i; j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        
    }
    return ans;
}

void printArray(int **ans, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int **ans = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        ans[i] = (int *)malloc((i+1) * sizeof(int));
    }
    ans = generate(n);
    printArray(ans, n);
    return 0;
}