#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void sieveOfEratosthenes(int num) {
    bool prime[num+1];
    int i,j;

    memset(prime, true, sizeof(prime));
    for(i=2; i*i<=num; i++) {
        if(prime[i]) {
            for(j=i*i; j<=num; j+=i) {
                prime[j] = false;
            }
        }
    }

    for(i=2; i<=num; i++) {
        if(prime[i])
            printf("%d ", i);
    }
}

int main(void) {
    int num;
    printf("Enter limit: ");
    scanf("%d", &num);
    printf("Prime numbers <= %d are: ", num);
    sieveOfEratosthenes(num);
    return 0;
}
