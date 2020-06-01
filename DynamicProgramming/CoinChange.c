#include <stdio.h>
#include <stdlib.h>

int coinChange(int arr[], int n, int amount) {
    int i, j, DP[amount+1];
    
    for(i=1; i<=amount; i++)
        DP[i] = 0;
        
    DP[0] = 1;
    
    for(i=0; i<n; i++) {
        for(j=arr[i]; j<=amount; j++) {
            DP[j] += DP[j-arr[i]];
        }
    }
    
    return DP[amount];
}

int main(void) {
    int i, n ,*arr, amount;
    printf("Enter number of available coins: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n * sizeof(int));
    
    printf("Enter %d coin values: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
        
    printf("Enter amount: ");
    scanf("%d",&amount);
    
    printf("%d\n",coinChange(arr, n, amount));
	return 0;
}


