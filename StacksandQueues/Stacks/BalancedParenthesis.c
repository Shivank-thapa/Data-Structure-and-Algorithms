#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 20

typedef struct Stack {
    char arr[SIZE];
    int top;
}Stack;

Stack *createStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack *st, char x) {
    if(st->top == SIZE-1) {
        printf("Stack Overflow!\n");
        return;
    }
    st->top++;
    st->arr[st->top] = x;
}

void pop(Stack *st) {
    if(st->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    char x = st->arr[st->top];
    st->top--;
}

bool pairMatch(char x, char y) {
    if((x == '(' && y == ')') || (x == '{' && y == '}') || (x == '[' && y == ']'))
        return true;
    return false;
}

bool checkBalance(char str[]) {
    int i;
    Stack *st = createStack();

    for(i=0; str[i] != '\0'; i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            push(st, str[i]);
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if(st->top == -1)
                return false;
            else if(!pairMatch(st->arr[st->top], str[i])) {
                return false;
            }
            pop(st);
        }
    }

    if(st->top == -1)       //check stack is empty in the end
        return true;
    return false;
}

int main(void) {
    char str[SIZE];

    printf("Enter string of parenthesis: ");
    scanf("%s", str);

    if(checkBalance(str)) {
        printf("Balanced parenthesis\n");
    }else {
        printf("Unbalanced parenthesis\n");
    }
    return 0;
}
