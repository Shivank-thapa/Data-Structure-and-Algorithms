#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 50

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node * createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Graph{
    int vertices;
    Node **adjLists;
    bool *visited;
}Graph;


Graph * createGraph(int num) {
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertices = num;
    newGraph->adjLists = malloc(num*sizeof(Node *));
    newGraph->visited = malloc(num*sizeof(bool));
    int i;
    for(i=0; i<num; i++) {
        newGraph->adjLists[i] = NULL;
        newGraph->visited[i] = false;
    }
    return newGraph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

typedef struct Queue {
    int arr[SIZE];
    int front;
    int rear;
}Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front=-1;
    q->rear=-1;
    return q;
}

bool isEmpty(Queue *q){
    if(q->rear == -1)
        return true;
    return false;
}

void enqueue(Queue *q, int num) {
    if(q->rear == SIZE-1) {
        printf("Queue is full!\n");
    }
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->arr[q->rear] = num;
    }
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->arr[q->front];
    q->front++;
    if(q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

void printQueue(Queue *q) {
    if(isEmpty(q))
        printf("Queue is empty!");
    else {
        int i;
        for(i=q->front; i <= q->rear; i++)
            printf("%d ",i);
        printf("\n");
    }
}

void bfs(Graph *graph, int start) {
    Queue *q = createQueue();

    graph->visited[start] = true;
    enqueue(q, start);

    while(!isEmpty(q)) {
        //printQueue(q);
        int current = dequeue(q);
        printf("%d ",current);
        Node *temp = graph->adjLists[current];
        while(temp) {
            int adj = temp->data;
            if(!(graph->visited[adj])) {
                graph->visited[adj] = true;
                enqueue(q, adj);
            }
            temp = temp->next;
        }
    }
}

int main(void){
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    bfs(graph, 0);
    return 0;
}
