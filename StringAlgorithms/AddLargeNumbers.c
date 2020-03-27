#include<stdio.h>
#include<string.h>
#define SIZE 300

void addNumbers(char n1[], char n2[]) {
    int i, sum, carry=0;
    int resLen = strlen(n1)-1 > strlen(n2)-1 ? strlen(n1)-1:strlen(n2)-1;

    char result[resLen+2];
    result[resLen+1] = '\0';
    int len1 = strlen(n1)-1;
    int len2 = strlen(n2)-1;

    while(len1 > 0 && len2 > 0) {
        sum = (n1[--len1]-'0') + (n2[--len2]-'0') + carry;
        result[resLen--] = (sum%10)+'0';
        carry = sum/10;
    }

    while(len1 > 0) {
        sum = (n1[--len1]-'0') + carry;
        result[resLen--] = (sum%10)+'0';
        carry = sum/10;
    }
    while(len2 > 0) {
        sum = (n2[--len2]-'0') + carry;
        result[resLen--] = (sum%10)+'0';
        carry = sum/10;
    }
    result[0] = carry+'0';

    printf("Sum is: ");
    if(result[0] == '0') {
        for(i=1; result[i]; i++)
            printf("%c", result[i]);
    }
    else {
        for(i=0; result[i]; i++)
            printf("%c", result[i]);
    }

}

int main(void) {
    char num1[SIZE], num2[SIZE];
    printf("Enter first number(can be larger than size of long long int): ");
    fgets(num1, SIZE, stdin);
    printf("Enter second number(can be larger than size of long long int): ");
    fgets(num2, SIZE, stdin);

    addNumbers(num1, num2);
    return 0;
}
