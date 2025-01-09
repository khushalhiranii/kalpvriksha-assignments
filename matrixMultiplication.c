#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void takeDimensionOfArrays(int *row1, int *row2, int *col1, int *col2){
    printf("Enter number of rows for 1st matrix: ");
    scanf("%d", row1);
    printf("Enter number of columns for 1st matrix: ");
    scanf("%d", col1);
    do{
        printf("Enter number of rows for 2nd matrix: ");
        scanf("%d", row2);
    }while(*row2 != *col1);
    printf("Enter number of columns for 2nd matrix: ");
    scanf("%d", col2);
}

void multiplyMatrix(int *row1, int *row2, int *col1, int *col2, int arr1[*row1][*col1], int arr2[*row2][*col2]){
    int **ans = (int **)malloc((*row1) * sizeof(int*));;
    for(int i=0;i<(*row1);i++){
        ans[i] = (int *)malloc((*col2) *sizeof(int));
    }
    
    for(int i=0; i<(*row1); i++){
        for(int j=0; j<(*col2); j++){
            int k=0;
            while(k<(*col1)){
                ans[i][j] += (arr1[i][k]) * (arr2[k][j]);
                k++;
            }
        }
    }
    for(int i=0; i<*row1; i++){
        for(int j=0; j<*(col2); j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
void initializeAndTakeInput(int *row1, int *row2, int *col1, int *col2){
    int arr1[*row1][*col1];
    int arr2[*row2][*col2];
    for(int i=0; i<(*row1); i++){
        for(int j=0; j<(*col1); j++){
            printf("Enter input for %d %d in 1st matrix: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    for(int i=0; i<(*row2); i++){
        for(int j=0; j<(*col2); j++){
            printf("Enter input for %d %d in 2nd matrix: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }
    multiplyMatrix(row1, row2, col1, col2, arr1, arr2);
}



int main(){
    int row1, col1 = 0;
    int row2, col2 = 0;
    takeDimensionOfArrays( &row1, &row2, &col1, &col2);
    initializeAndTakeInput( &row1, &row2, &col1, &col2);
    
}
