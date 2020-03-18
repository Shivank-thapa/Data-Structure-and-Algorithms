#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 50

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Graph {
    int vertices;
    Node **adjLists;
    bool *visited;
}Graph;

Graph *createGraph(int vertices) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertices = vertices;
    g->adjLists = malloc(vertices * sizeof(Node *));
    g->visited = malloc(vertices * sizeof(bool));
    int i;
    for(i=0; i<vertices; i++) {
        g->adjLists[i] = NULL;
        g->visited[i] = false;
    }
    return g;
}

void addEdge(Graph *g, int src, int dest) {
    Node *newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

}

typedef struct Stack {
    int top;
    int arr[SIZE];
}Stack;

Stack *createStack() {
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = -1;
    return st;
}

bool isEmpty(Stack *st) {
    if(st->top == -1)
        return true;
    return false;
}

void push(Stack *st, int data) {
    if(st->top == SIZE-1){
        printf("Stack is full!\n");
        return;
    }
    st->top++;
    st->arr[st->top] = data;
}

int pop(Stack *st) {
    if(isEmpty(st)) {
        printf("Stack is empty!\n");
        return -1;
    }
    int item = st->arr[st->top];
    st->top--;
    return item;
}

void topologicalSortUtil(int currentVertex, Graph *g, Stack *st) {
    g->visited[currentVertex] = true;
    Node *adjList = g->adjLists[currentVertex];
    Node *temp = adjList;

    while(temp) {
        int nextVetex = temp->data;
        if(!(g->visited[nextVetex])) {
            topologicalSortUtil(nextVetex, g, st);
        }
        temp = temp->next;
    }

    push(st, currentVertex);
}

void topologicalSort(Graph *g) {
    Stack *st = createStack();
    int i;

    for(i=0; i<g->vertices; i++) {
        if(!(g->visited[i])) {
            topologicalSortUtil(i, g, st);
        }
    }
    while(!(isEmpty(st))) {
        printf("%d ", pop(st));
    }
}

int main(void) {
    Graph *g = createGraph(8);
    addEdge(g, 0, 6);
    addEdge(g, 1, 2);
    addEdge(g, 1, 4);
    addEdge(g, 1, 6);
    addEdge(g, 3, 0);
    addEdge(g, 3, 4);
    addEdge(g, 5, 1);
    addEdge(g, 7, 0);
    addEdge(g, 7, 1);

    topologicalSort(g);

    return 0;
}

