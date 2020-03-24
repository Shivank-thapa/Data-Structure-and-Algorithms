#include<stdio.h>
#include<stdlib.h>

void printMatrix(int m, int n, int matrix[][n]) {
    int i, j;
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void rotateMatrix(int m, int n, int matrix[][n]) {
    int row = 0, col = 0, i;
    int prev, curr;
    while(row < m && col < n) {
        if(row+1 == m || col+1 == n)
            break;

        prev = matrix[row+1][col];

        for(i=col; i<n; i++) {
            curr = matrix[row][i];
            matrix[row][i] = prev;
            prev = curr;
        }
        row++;

        for(i=row; i<m; i++) {
            curr = matrix[i][n-1];
            matrix[i][n-1] = prev;
            prev = curr;
        }
        n--;

        if(row < m) {
            for(i=n-1; i>=col; i--) {
                curr = matrix[m-1][i];
                matrix[m-1][i] = prev;
                prev = curr;
            }
        }
        m--;

        if(col < n) {
            for(i=m-1; i>=row; i--) {
                curr = matrix[i][col];
                matrix[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

int main(void){
    int rows, cols, i, j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter matrix of size %d X %d\n", rows, cols);
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            scanf("%d", &matrix[i][j]);

    printf("Matrix before rotation\n");
    printMatrix(rows, cols, matrix);

    rotateMatrix(rows, cols, matrix);

    printf("Matrix after rotation\n");
    printMatrix(rows, cols, matrix);
    return 0;
}
