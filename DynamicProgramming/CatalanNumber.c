// Program to calculate n'th Catalan number
// Catalan number gives the number of BST possible with n nodes, number of possible parathesis, etc

#include <stdio.h>

int catalan(int n) {
    int i,j;
    int cat[n+1];
    
    cat[0] = cat[1] = 1;
    
    for (i = 2; i <= n; i++) {
        cat[i] = 0;
        for(j = 0; j < i; j++) {
            cat[i] += cat[j] * cat[i-j-1];
        }
    }
    
    return cat[n];
}

int main(void) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d\n", catalan(n));
	return 0;
}
