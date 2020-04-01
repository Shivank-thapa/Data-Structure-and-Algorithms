#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define LIMIT 50

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}

typedef struct Queue {
    Node *queue[LIMIT];
    int front;
    int rear;
}Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    return q;
}

bool isEmpty(Queue *q) {
    return q->front==-1;
}

bool isFull(Queue *q) {
    if((q->front == 0 && q->rear == LIMIT-1) || (q->front == q->rear+1))
        return true;
    return false;
}

void enqueue(Queue *q, Node *p) {
    if(isFull(q)) {
        printf("QUEUE IS FULL!\n");
        return;
    }
    if(q->front == -1)
        q->front = q->rear = 0;
    else if(q->rear == LIMIT-1)
        q->rear = 0;
    else
        q->rear++;
    q->queue[q->rear] = p;
}

Node *dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("QUEUE IS EMPTY!\n");
        return NULL;
    }
    Node *p = q->queue[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else if(q->front == LIMIT-1)
        q->front = 0;
    else
        q->front++;
    return p;
}

Node *front(Queue *q) {
    if(isEmpty(q)) {
        printf("QUEUE IS EMPTY!\n");
        return NULL;
    }
    return q->queue[q->front];
}

Node *rear(Queue *q) {
    if(isEmpty(q)) {
        printf("QUEUE IS EMPTY!\n");
        return NULL;
    }
    return q->queue[q->rear];
}

void printLevelOrder(Node *root) {
    Queue *q = createQueue();
    Node *tmp;
    enqueue(q, root);

    while(!isEmpty(q)) {
        tmp = front(q);
        printf("%d ", tmp->data);
        dequeue(q);

        if(tmp->left) {
            enqueue(q, tmp->left);
        }
        if(tmp->right) {
            enqueue(q, tmp->right);
        }
    }
}

int main(void) {
    Node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    printLevelOrder(root);
    return 0;
}
