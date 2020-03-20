#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 50

typedef struct queue {
    int arr[SIZE];
    int front;
    int rear;
}Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue *q) {
    if((q->front == 0 && q->rear == SIZE-1) || q->front == q->rear+1) {
        return true;
    }
    return false;
}

bool isEmpty(Queue *q) {
    if(q->front == -1)
        return true;
    return false;
}

void enqueue(Queue *q, int data) {
    if(isFull(q)) {
        printf("Overflow!\n");
        return;
    }
    if(q->front == -1)
        q->front = q->rear = 0;
    else if(q->rear == SIZE-1)
        q->rear = 0;
    else
        q->rear++;
    q->arr[q->rear] = data;
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Underflow!\n");
        return;
    }
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else if(q->front == SIZE-1)
        q->front = 0;
    else
        q->front++;
}

int getFront(Queue *q) {
    if(isEmpty(q)){
        printf("Underflow!\n");
        return -1;
    }
    return q->arr[q->front];
}

int getRear(Queue *q) {
    if(isEmpty(q)){
        printf("Underflow!\n");
        return -1;
    }
    return q->arr[q->rear];
}

typedef struct Stack {
    Queue *q1;
    Queue *q2;
}Stack;

Stack *createStack() {
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->q1 = createQueue();
    st->q2 = createQueue();
    return st;
}

void push(Stack *st, int data) {
    enqueue(st->q2, data);
    while(!(isEmpty(st->q1))) {
        enqueue(st->q2, getFront(st->q1));
        dequeue(st->q1);
    }

    Queue *temp;
    temp = st->q1;
    st->q1 = st->q2;
    st->q2 = temp;
}

void pop(Stack *st) {
    dequeue(st->q1);
}

int top(Stack *st) {
    return getFront(st->q1);
}

int main(void) {
    int choice, num;
    bool flag = true;
    Stack *st = createStack();
    do {
        printf("Enter operation to perform\n");
        printf("1.Push.\n2.Pop.\n3.Top.\n4.Exit.\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &num);
            push(st, num);
            break;
        case 2:
            pop(st);
            break;
        case 3:
            printf("%d\n", top(st));
            break;
        case 4:
            flag = false;
            break;
        default:
            printf("Enter a valid choice!\n");
        }
    } while(flag);

    return 0;
}
