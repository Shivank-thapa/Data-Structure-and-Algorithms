#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int knapsack(int weight[], int profit[], int W, int n) {
    int i, j;
    int DP[n+1][W+1];
    
    for(i=0; i<=n; i++) {
        for(j=0; j<=W; j++) {
            if(i == 0 || j == 0)
                DP[i][j] = 0;
            else if(weight[i-1] <= j)
                DP[i][j] = max(DP[i-1][j-weight[i-1]] + profit[i-1], DP[i-1][j]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][W];
}

int main(void) {
	int i, n, W, *weight, *profit;
	printf("Enter number of items: ");
	scanf("%d", &n);
	
	weight = (int *)malloc(n * sizeof(int));
	profit = (int *)malloc(n * sizeof(int));
	
	printf("Enter weight and profit of %d items: ", n);
	for(i=0; i<n; i++)
	    scanf("%d %d",&weight[i], &profit[i]);
	 
	printf("Enter weight of knapsack: ");
	scanf("%d", &W);
	
	printf("Maximum profit with knapsack of weight %d is: %d\n", W, knapsack(weight, profit, W, n));
	return 0;
}


