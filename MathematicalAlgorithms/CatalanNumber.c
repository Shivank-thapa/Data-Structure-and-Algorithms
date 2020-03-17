#include<stdio.h>

int catalan(int num) {
    if(num <= 1) {
        return 1;
    }
    int i, res = 0;
    for(i=0; i<num; i++) {
        res += catalan(i)*catalan(num-1-i);
    }
    return res;
}

int main(void) {
    int num;
    printf("Enter index of Catalan number to find: ");
    scanf("%d",&num);
    printf("%d ", catalan(num));
    return 0;
}
