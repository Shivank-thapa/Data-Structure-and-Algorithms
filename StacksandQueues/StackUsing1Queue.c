#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 50

typedef struct queue {
    int arr[SIZE];
    int front;
    int rear;
    int size;
}Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
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
    q->size++;
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
    q->size--;
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
    Queue *q;
}Stack;

Stack *createStack() {
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->q = createQueue();
    return st;
}

void push(Stack *st, int data) {
    int n = st->q->size;

    enqueue(st->q, data);
    while(n > 0) {
        enqueue(st->q, getFront(st->q));
        dequeue(st->q);
        n--;
    }
}

void pop(Stack *st) {
    if(isEmpty(st->q)) {
        printf("Underflow!\n");
        return;
    }
    dequeue(st->q);
}

int top(Stack *st) {
    if(isEmpty(st->q)) {
        printf("Underflow!\n");
        return -1;
    }
    getFront(st->q);
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
