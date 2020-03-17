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

void dfs(Graph *graph, int start) {
    Node *adjList = graph->adjLists[start];
    Node *tmp = adjList;

    graph->visited[start] = true;
    printf("%d ",start);

    while(tmp) {
        int nextVertex = tmp->data;
        if(!(graph->visited[nextVertex])) {
            dfs(graph, nextVertex);
        }
        tmp = tmp->next;
    }
}

int main(void){
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    dfs(graph, 2);
    return 0;
}

