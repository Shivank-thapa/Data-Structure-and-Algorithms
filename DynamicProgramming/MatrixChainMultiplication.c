#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int matrixChainMul(int p[], int n) {
    int table[n][n];
    int i,j,k,len,cost;
    
    for(i=1; i<n; i++) 
        table[i][i] = 0;
    
    for(len=2; len < n; len++) {
        for(i=1; i < n-len+1; i++) {
            j = i+len-1;
            table[i][j] = INT_MAX;
            for(k=i; k <= j-1; k++) {
                cost = table[i][k] + table[k+1][j] + p[i-1]*p[k]*p[j];
                if(cost < table[i][j])
                    table[i][j] = cost;
            }
        }
    }
    return table[1][n-1];
}

int main(void) {
    int i, n, *p;
    
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    
    p = (int *)malloc((n+1)*sizeof(int));
    
    printf("Enter dimension array of size %d: ",n+1);
    for(i=0; i<=n; i++)
        scanf("%d", &p[i]);
    
    printf("Minimum number of multiplications required are: ");
    printf("%d\n", matrixChainMul(p, n+1));
	return 0;
}
