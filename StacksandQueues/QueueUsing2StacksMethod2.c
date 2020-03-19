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

void push(Stack *st, int data) {
    if(st->top == SIZE-1) {
        printf("Overflow!\n");
        return;
    }
    st->top++;
    st->arr[st->top] = data;
}

void pop(Stack *st) {
    if(st->top == -1) {
        printf("Underflow!\n");
        return;
    }
    st->top--;
}

int top(Stack *st) {
    if(st->top == -1) {
        printf("Underflow!\n");
        return -1;
    }
    return st->arr[st->top];
}

typedef struct Queue {
    Stack *s1;
    Stack *s2;
}Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->s1 = createStack();
    q->s2 = createStack();
    return q;
}

void enqueue(Queue *q, int data) {
    push(q->s1, data);
}

void dequeue(Queue *q) {
    if(q->s1->top == -1 && q->s2->top == -1) {
        printf("Underflow.\n");
        return;
    }

    if(q->s2->top == -1) {
        while(q->s1->top != -1) {
            push(q->s2, top(q->s1));
            pop(q->s1);
        }
    }

    int x = top(q->s2);
    printf("Dequeued %d\n",x);
    pop(q->s2);
}

int main(void) {
    int choice, num;
    bool flag = true;
    Queue *q = createQueue();
    do {
        printf("Enter operation to perform\n");
        printf("1.Enqueue.\n2.Dequeue.\n3.Exit.\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &num);
            enqueue(q, num);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            flag = false;
            break;
        default:
            printf("Enter a valid choice!\n");
        }
    } while(flag);

    return 0;
}

