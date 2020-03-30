#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 50

typedef struct Stack {
    int arr[SIZE];
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

void push(Stack *st, int data) {
    if(isFull(st)) {
        printf("STACK OVERFLOW!\n");
        return;
    }
    st->top++;
    st->arr[st->top] = data;
}

int pop(Stack *st) {
    if(isEmpty(st)) {
        printf("STACK UNDERFLOW!\n");
        exit(0);
    }
    int data = st->arr[st->top];
    st->top--;
    return data;
}

int top(Stack *st) {
    if(isEmpty(st)) {
        printf("STACK IS EMPTY!\n");
        exit(0);
    }
    return st->arr[st->top];
}

void calculateSpan(int price[], int n) {
    Stack *st = createStack();      //stack to store days
    int *span = (int *)malloc(n * sizeof(int));     //span array to store span for each day
    int i;

    push(st, 0);
    span[0] = 1;    //span of first element is always 1

    for(i=1; i<n; i++) {
        while(!isEmpty(st) && price[top(st)] <= price[i]) {
            pop(st);
        }

        if(isEmpty(st)) {   //if stack is empty current day's price is greater than all prices to its left
            span[i] = i+1;
        }
        else {              //else current day's price is greater than all elements after stack
            span[i] = i-top(st);
        }
        push(st, i);
    }
    printf("Span for each day is: ");
    for(i=0; i<n; i++) {
        printf("%d ", span[i]);
    }
}

int main(void) {
    int i, size;
    printf("Enter number of days: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter price for %d days: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);

    calculateSpan(arr, size);
    return 0;
}

