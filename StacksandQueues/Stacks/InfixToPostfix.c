#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 50

typedef struct Stack {
    char arr[SIZE];
    int top;
}Stack;

Stack *createStack() {
    Stack *st = (Stack *)malloc(sizeof(Stack));

    st->top = -1;
    return st;
}

bool isEmpty(Stack *st) {
    if(st->top == -1)
        return true;
    return false;
}

bool isFull(Stack *st) {
    if(st->top == SIZE-1)
        return true;
    return false;
}

void push(Stack *st, char data) {
    if(isFull(st)) {
        printf("STACK OVERFLOW!\n");
        return;
    }
    st->top++;
    st->arr[st->top] = data;
}

void pop(Stack *st) {
    if(isEmpty(st)) {
        printf("STACK UNDERFLOW!\n");
        return;
    }
    st->top--;
}

char top(Stack *st) {
    if(isEmpty(st)) {
        printf("STACK IS EMPTY!\n");
        return '$';
    }
    return st->arr[st->top];
}

bool isOperand(char x) {
    if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
        return true;
    return false;
}

int precedence(char x) {
    switch(x) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void convertToPostfix(char str[]) {
    Stack *st = createStack();
    int i, k=0;
    char res[strlen(str)];
    for(i=0; str[i] != '\0'; i++) {
        if(isOperand(str[i])) {
            res[k++] = str[i];
        }
        else if(str[i] == '(') {
            push(st, '(');
        }
        else if(str[i] == ')') {
            while(!isEmpty(st) && top(st) != '(') {
                res[k++] = top(st);
                pop(st);
            }
            pop(st);
        }
        else {
            while(!isEmpty(st) && precedence(str[i]) <= precedence(top(st))) {
                res[k++] = top(st);
                pop(st);
            }
            push(st, str[i]);
        }
    }

    while(!isEmpty(st)) {
        res[k++] = top(st);
        pop(st);
    }
    res[k++] = '\0';
    printf("Postfix expression is: %s\n", res);
}


int main(void) {
    char str[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", str);

    convertToPostfix(str);
    return 0;
}
