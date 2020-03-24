#include<stdio.h>
#include<stdlib.h>

void printSpiralMatrix(int m, int n, int matrix[][n]) {
    int row = 0, col = 0, i;

    while(row < m && col < n) {
        for(i=col; i<n; i++)
            printf("%d ", matrix[row][i]);
        row++;

        for(i=row; i<m; i++)
            printf("%d ", matrix[i][n-1]);
        n--;

        if(row < m) {
            for(i=n-1; i>=col; i--)
                printf("%d ", matrix[m-1][i]);
            m--;
        }

        if(col < n) {
            for(i=m-1; i>=row; i--)
                printf("%d ", matrix[i][col]);
            col++;
        }
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

    printSpiralMatrix(rows, cols, matrix);

    return 0;
}

