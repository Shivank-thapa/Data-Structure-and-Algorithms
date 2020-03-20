#include<stdio.h>
#include<stdbool.h>
#define capacity 5

int front = -1;
int rear = -1;

void enqueue(int q[], int num) {
    if((front == 0 && rear == capacity-1) || (rear == (front-1)%(capacity-1))) {
        printf("Overflow! Queue is full.\n");
        return;
    }
    if(front == -1) {
        front++;
        rear++;
    }
    else if(front != 0 && rear == capacity-1)
        rear = 0;
    else
        rear++;
    q[rear] = num;
    printf("Enqueued successfully!\n");
}

void dequeue(int q[]) {
    if(front == -1) {
        printf("Underflow! Queue is empty.\n");
        return;
    }
    if(front == capacity-1)
        front = 0;
    else if(front == rear)
        front = rear = -1;
    else
        front++;
    printf("Dequeued successfully!\n");
}

void frontE(int q[]) {
    if(front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element is: %d\n", q[front]);
}

void rearE(int q[]) {
    if(front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Rear element is: %d\n", q[rear]);
}

int main(void) {
    int queue[capacity];
    int choice, num;
    bool flag = true;

    do {
        printf("Enter operation to perform\n");
        printf("1.Enqueue\n2.Dequeue\n3.Front\n4.Rear\n5.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &num);
            enqueue(queue, num);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            frontE(queue);
            break;
        case 4:
            rearE(queue);
            break;
        case 5:
            flag = false;
            break;
        default:
            printf("Enter a valid choice!\n");
        }
    } while(flag);
    return 0;
}

