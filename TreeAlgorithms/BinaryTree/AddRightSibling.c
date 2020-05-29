#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LIMIT 20

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *rightSibling;
}Node;

Node *createNode(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->rightSibling = NULL;
    
    return p;
}

typedef struct Queue{
    Node *arr[LIMIT];
    int front;
    int rear;
    int capacity;
}Queue;

Queue *createQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->capacity = size;
    
    return q;
}

bool isFull(Queue *q){
    if((q->rear + 1)%q->capacity == q->front)
        return true;
    return false;
}

bool isEmpty(Queue *q) {
    if(q->front == -1)
        return true;
    return false;
}

void enqueue(Queue *q, Node *data) {
    if(isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1)%q->capacity;
    q->arr[q->rear] = data;
    if(q->front == -1)
        q->front = 0;
}    

Node *dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return NULL;
    }
    Node *tmp = q->arr[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1)%q->capacity;
        
    return tmp;
}

void connectRightSiblings(Node *root) {
    Node *tmp;
    Queue *q = createQueue(LIMIT);
    
    if(!root)
        return;
        
    enqueue(q, root);
    enqueue(q, NULL);
    
    while(!isEmpty(q)) {
        tmp = dequeue(q);
        
        if(tmp == NULL) {       // indicates current level is completed
            if(!isEmpty(q))
                enqueue(q, NULL);
        }
        else {
            tmp->rightSibling = q->arr[q->front];
            if(tmp->left)
                enqueue(q, tmp->left);
            if(tmp->right)
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
    
    connectRightSiblings(root);
	return 0;
}


