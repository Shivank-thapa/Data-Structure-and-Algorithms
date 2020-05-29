#include <stdio.h>
#define SIZE 35

int f[SIZE];

int fib(int n) {
	int i;
	f[0] = 1;
	f[1] = 1;
	for(i=2; i<n; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	return f[n-1];
}

int main(void) {
	int n;
	printf("Enter a number: ");	
	scanf("%d",&n);
	printf("%d\n",fib(n));

	return 0;
}
