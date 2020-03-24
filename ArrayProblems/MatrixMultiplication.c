#include<stdio.h>
#include<stdlib.h>

void multiplyMatrices(int m, int n, int A[][n], int B[][n]) {
    int i, j, k;
    int C[m][n];

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            C[i][j] = 0;
            for(k=0; k<n; k++) {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }

    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int rows, cols, i, j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols];
    printf("Enter matrix-1 of size %d X %d\n", rows, cols);
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            scanf("%d", &matrix1[i][j]);

    printf("Enter matrix-2 of size %d X %d\n", rows, cols);
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            scanf("%d", &matrix2[i][j]);

    multiplyMatrices(rows, cols, matrix1, matrix2);

    return 0;
}

