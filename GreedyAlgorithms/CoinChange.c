/* Given infinite supply of each denomination in Indian currency, find minimum
number of coins/notes needed to make the given sum of money */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

int change[] = {1,2,5,10,20,50,100,200,500,1000,2000};

int minChange(int amount) {
    int n = sizeof(change)/sizeof(change[0]);
    int i, j=0, result[SIZE] = {0};
    
    for(i=n-1; i>=0; i--) {
        while(amount >= change[i]) {
            amount -= change[i];
            result[j++] = change[i];
        }
    }
    
    for(i=0; i<j; i++)
        printf("%d ",result[i]);
    printf("\n");
}

int main(void) {
    int amount;
    printf("Enter amount: ");
    scanf("%d", &amount);
    printf("Minimum number of change is: ");
    minChange(amount);
	return 0;
}


