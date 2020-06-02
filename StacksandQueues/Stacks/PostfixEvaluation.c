#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 1000

typedef struct Stack {
    int size;
    int *arr;
    int top;
}Stack;

Stack *createStack(int n) {
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->size = n;
    st->top = -1;
    st->arr = (int *)malloc(n * sizeof(int));
    
    return st;
}

bool isEmpty(Stack *st) {
    return st->top == -1;
}

int pop(Stack *st) {
    if(!isEmpty(st)) {
        return st->arr[st->top--];
    }
    return -10000;
}

void push(Stack *st, int x) {
    st->arr[++st->top] = x;
}

int evaluatePostfixExpression(char *str) {
    int i, n = strlen(str);
    Stack *st = createStack(n);
    
    for(i=0; i<n; i++) {
        if(str[i] >= '0' && str[i] <= '9')
            push(st, str[i]-'0');
        else {
            int d1 = pop(st);
            int d2 = pop(st);
            switch(str[i]) {
                case '+':
                    push(st, d2+d1);
                    break;
                case '-':
                    push(st, d2-d1);
                    break;
                case '*':
                    push(st, d2*d1);
                    break;
                case '/':
                    push(st, d2/d1);
                    break;
            }
        }
    }
    return pop(st);
}

int main(void) {
	char str[SIZE];
	printf("Enter postfix expression to evaluate: ");
	fgets(str, SIZE, stdin);
	printf("Result of given postfix expression is: %d\n", evaluatePostfixExpression(str));
	return 0;
}


