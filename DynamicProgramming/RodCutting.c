#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getMax(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int cutRod(int price[], int n) {
    int i, j, max, DP[n+1];
    
    DP[0] = 0;
    
    for(i=1; i<=n; i++) {
        max = INT_MIN;
        for(j=0; j<i; j++) {
            max = getMax(max, price[j] + DP[i-j-1]);
        }
        DP[i] = max;
    }
    
    return DP[n];
}

int main(void) {
	int i, n, *price;
	
	printf("Enter length of rod: ");
	scanf("%d", &n);
	
	price = (int *)malloc(n * sizeof(int));
	
	printf("Enter price list for %d pieces: ",n);
	for(i=0; i<n; i++) 
	    scanf("%d", &price[i]);
	  
	printf("Maximum profit that can be obtained is: %d\n", cutRod(price, n)); 
	return 0;
}


