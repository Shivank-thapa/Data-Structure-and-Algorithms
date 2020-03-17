#include<stdio.h>

int fib(int num) {
  int i, a = 0, b = 1, c;
  if( num == 0)
    return a;
  for (i = 2; i <= num; i++) {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}

int main(void) {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    printf("%d",fib(num));
    return 0;
}
