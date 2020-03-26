#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 100

typedef struct Stack {
    char arr[SIZE];
    int top;
}Stack;

Stack *createStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack *s) {
    if(s->top == SIZE-1)
        return true;
    return false;
}

bool isEmpty(Stack *s) {
    if(s->top == -1)
        return true;
    return false;
}

void push(Stack *s, char x) {
    if(isFull(s)) {
        printf("STACK OVERFLOW!\n");
        return;
    }
    s->top++;
    s->arr[s->top] = x;
}

char pop(Stack *s) {
    if(isEmpty(s)) {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
    char x = s->arr[s->top];
    s->top--;
    return x;
}

char top(Stack *s) {
    if(isEmpty(s)) {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
    return s->arr[s->top];
}

void reverseWords(char str[]) {
    Stack *s = createStack();
    int i;

    for(i=0; str[i] != '\0'; i++) {
        if(str[i] != ' ') {
            push(s, str[i]);
        }
        else {
            while(!isEmpty(s)) {
                printf("%c",pop(s));
            }
            printf(" ");
        }
    }
    while(!isEmpty(s)) {
            printf("%c",pop(s));
    }
}

int main(void) {
    char str[SIZE];

    printf("Enter your string: ");
    fgets(str, SIZE, stdin);

    reverseWords(str);

    return 0;
}
