#include<stdio.h>

void printMatrix(int n, int m, int matrix[][m]) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swapDiagonals(int n, int m, int mat[][m]) {
    int temp, i;
    for(i=0; i<n; i++) {
        temp = mat[i][i];
        mat[i][i] = mat[i][n-1-i];
        mat[i][n-1-i] = temp;
    }
}

int main(void) {
    int i, j, size;
    printf("Enter matrix size: ");
    scanf("%d", &size);
    int matrix[size][size];

    printf("Enter %d X %d matrix: ", size, size);
    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
            scanf("%d", &matrix[i][j]);

    printf("Matrix before swapping diagonals:\n");
    printMatrix(size, size, matrix);

    swapDiagonals(size, size, matrix);

    printf("Matrix after swapping diagonals:\n");
    printMatrix(size, size, matrix);
    return 0;
}
