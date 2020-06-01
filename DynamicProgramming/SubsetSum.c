#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool subsetSum(int arr[], int n, int sum) {
    int i,j;
    int DP[n+1][sum+1];
    
    for(i=0; i<=n; i++)
        DP[i][0] = true;
    
    for(i=1; i<=sum; i++)
        DP[0][i] = false;
        
    for(i=1; i<=n; i++) {
        for(j=1; j<=sum; j++) {
            if(j < arr[i-1])
                DP[i][j] = DP[i-1][j];
            else {
                DP[i][j] = DP[i-1][j-arr[i-1]] || DP[i-1][j];
            }
        }
    }
    
    return DP[n][sum];
}

int main(void) {
    int i, n, *arr, sum;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n * sizeof(int));
    
    printf("Enter %d array elements: ",n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
        
    printf("Enter sum value to check: ");
    scanf("%d", &sum);
    
    bool result = subsetSum(arr, n, sum);
    
    if(!result) {
        printf("Subset with given sum not found!\n");
    }
    else {
        printf("Found a subset with given sum!\n");
    }
	return 0;
}


