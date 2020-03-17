#include<stdio.h>

int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main(void) {
    int a,b;
    printf("Enter 2 numbers to find gcd: ");
    scanf("%d %d",&a, &b);
    printf("GCD(%d, %d) is %d", a,b,gcd(a,b));
    return 0;
}
