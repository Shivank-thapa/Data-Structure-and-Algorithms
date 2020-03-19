#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 50

typedef struct Dequeue {
    int arr[SIZE];
    int front;
    int rear;
}Dequeue;

Dequeue *createDequeue() {
    Dequeue *q = (Dequeue *)malloc(sizeof(Dequeue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Dequeue *q) {
    if((q->front == 0 && q->rear == SIZE-1) || q->front == q->rear+1) {
        return true;
    }
    return false;
}

bool isEmpty(Dequeue *q) {
    if(q->front == -1)
        return true;
    return false;
}

void insertRear(Dequeue *q, int data) {
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

void insertFront(Dequeue *q, int data) {
    if(isFull(q)) {
        printf("Overflow!\n");
        return;
    }
    if(q->front == -1)
        q->front = q->rear = 0;
    else if(q->front == 0)
        q->front = SIZE-1;
    else
        q->front--;
    q->arr[q->front] = data;
}

void deleteFront(Dequeue *q){
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

void deleteRear(Dequeue *q) {
    if(isEmpty(q)){
        printf("Underflow!\n");
        return;
    }
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else if(q->rear == 0)
        q->rear = SIZE-1;
    else
        q->rear--;
}

int getFront(Dequeue *q) {
    if(isEmpty(q)){
        printf("Underflow!\n");
        return -1;
    }
    return q->arr[q->front];
}

int getRear(Dequeue *q) {
    if(isEmpty(q)){
        printf("Underflow!\n");
        return -1;
    }
    return q->arr[q->rear];
}

int main(void) {
    int choice, num;
    bool flag = true;
    Dequeue *dequeue = createDequeue();
    do {
        printf("Enter operation to perform\n");
        printf("1.Enqueue from rear\n2.Enqueue from front\n3.Dequeue from front\n4.Dequeue from rear\n5.Front\n6.Rear.\n7.Exit.\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &num);
            insertRear(dequeue, num);
            break;
        case 2:
            printf("Enter element to enqueue: ");
            scanf("%d", &num);
            insertFront(dequeue, num);
            break;
        case 3:
            deleteFront(dequeue);
            break;
        case 4:
            deleteRear(dequeue);
            break;
        case 5:
            printf("%d\n", getFront(dequeue));
            break;
        case 6:
            printf("%d\n", getRear(dequeue));
            break;
        case 7:
            flag = false;
            break;
        default:
            printf("Enter a valid choice!\n");
        }
    } while(flag);
    return 0;
}
