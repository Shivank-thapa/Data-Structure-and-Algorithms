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

void nextGreater(int arr[], int n) {
    Stack *st = createStack();
    int i, next, element;

    push(st, arr[0]);   //push first element in stack
    for(i=1; i<n; i++) {
        next = arr[i];
        if(!isEmpty(st)) {
            element = pop(st);
            while(element < next) {
                printf("%d --> %d\n", element, next);
                if(isEmpty(st))
                    break;
                element = pop(st);
            }
            if(element > next) {
                push(st, element);
            }
        }
        push(st, next);
    }
    while(!isEmpty(st)) {
        element = pop(st);
        printf("%d --> -1\n", element);
    }
}

int main(void) {
    int i, size;
    printf("Enter size: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter %d elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);

    nextGreater(arr, size);
    return 0;
}
