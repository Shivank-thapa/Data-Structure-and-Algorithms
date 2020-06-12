#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 100

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    
    return p;
}

typedef struct Graph {
    int vertices;
    Node **adjLists;
}Graph;

Graph *createGraph(int v) {
    int i;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertices = v;
    g->adjLists = malloc(v * sizeof(Node *));
    for(i=0; i<v; i++)
        g->adjLists[i] = NULL;
    
    return g;
}

void addEdge(Graph *g, int u, int v) {
    Node *tmp = createNode(v);
    tmp->next = g->adjLists[u];
    g->adjLists[u] = tmp;
}

typedef struct Queue {
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
    if((q->rear + 1)%SIZE == q->front)
        return true;
    return false;
}

bool isEmpty(Queue *q) {
    if(q->front == -1)
        return true;
    return false;
}

void enqueue(Queue *q, int data) {
    if(isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1)%SIZE;
    q->arr[q->rear] = data;
    if(q->front == -1)
        q->front = 0;
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return -100;
    }
    int x = q->arr[q->front];
    if(q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front = (q->front + 1)%SIZE;
    }
    return x;
}

bool pathExists(Graph *g, int src, int dest) {
    int i;
    
    if(src == dest)
        return true;
    
    bool *visited = (bool *)malloc(g->vertices * sizeof(int));
    for(i=0; i<g->vertices; i++)
        visited[i] = false;
    
    Queue *q = createQueue();
    visited[src] = true;
    enqueue(q, src);
    
    while(!isEmpty(q)) {
        int u = dequeue(q);
        
        Node *tmp = g->adjLists[u];
        while(tmp) {
            if(tmp->data == dest)
                return true;
            if(!visited[tmp->data]) {
                visited[tmp->data] = true;
                enqueue(q, tmp->data);
            }
			tmp = tmp->next;
        }
    }
    
}

int main(void) {
    int v, e , i , src, dest;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &v, &e);
    
    Graph *graph = createGraph(v);
    
    printf("Enter %d directed edges: ", e);
    for(i=0; i<e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    printf("Enter source and destination vertices to check path between them: ");
    scanf("%d %d", &src, &dest);
    
    if(pathExists(graph, src, dest))
        printf("There exists a path from %d to %d\n", src, dest);
    else
        printf("There exists no path from %d to %d\n", src, dest);
	return 0;
}


