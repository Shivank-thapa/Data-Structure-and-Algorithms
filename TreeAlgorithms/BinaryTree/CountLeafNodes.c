#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define SIZE 20

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;


Node *createNode(int x){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

typedef struct Queue {
    Node *queue[SIZE];
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
    if(q->front == -1)
        return true;
    return false;
}

bool isFull(Queue *q) {
    if((q->front == 0 && q->rear == SIZE-1) || (q->front == q->rear+1))
        return true;
    return false;
}

void enqueue(Queue *q, Node *p) {
    if(isFull( q)) {
        printf("Queue is Full!\n");
        return;
    }
    if(q->front == -1)
        q->front = q->rear = 0;
    else if(q->rear == SIZE-1)
        q->rear = 0;
    else
        q->rear++;
    q->queue[q->rear] = p;
}

Node *dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return NULL;
    }
    Node *p = q->queue[q->front];
    
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else if(q->front == SIZE-1)
        q->front = 0;
    else
        q->front++;
        
    return p;
}

int getLeaves(Node *root) {
    int c = 0;
    Queue *q = createQueue();
    Node *tmp;
    
    enqueue(q, root);
    while(!isEmpty(q)) {
        tmp = dequeue(q);
        if(!tmp->left && !tmp->right)
            c++;
        else {
            if(tmp->left)
                enqueue(q, tmp->left);
            if(tmp->right)
                enqueue(q, tmp->right);
        }
    }
    return c;
    
}

int main(void) {
    Node *root = createNode(1);
    root->left = createNode(11);
    root->right = createNode(900);
    root->left->left = createNode(5421);
    root->left->right = createNode(123);
    root->right->right = createNode(21);
    
    int count = getLeaves(root);
    
    printf("Number of leaf nodes are: %d\n",count);
	return 0;
}

