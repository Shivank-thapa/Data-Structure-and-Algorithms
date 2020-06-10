#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int src;
    int dest;
}Edge;

typedef struct Graph {
    int V;
    int E;
    Edge *edges;
} Graph;

Graph *createGraph(int v, int e) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    
    g->V = v;
    g->E = e;
    g->edges = (Edge *)malloc(e * sizeof(Edge));
	
	return g;
}

void addEdge(Graph *g, int src, int dest, int index) {
    g->edges[index].src = src;
    g->edges[index].dest = dest;
}

int findSet(int parent[], int x) {
    if(parent[x] == -1)
        return x;
    return findSet(parent, parent[x]);
}

void Union(int x, int y, int parent[]) {
    int xSet = findSet(parent, x);
    int ySet = findSet(parent, y);
    
    if(xSet != ySet)
        parent[xSet] = ySet; 
}

int isCycle(Graph *g) {
    int i;
    int *parent = (int *)malloc(g->V * sizeof(int));
    
    for(i=0; i<g->V; i++)
        parent[i] = -1;
        
    for(i=0; i<g->E; i++) {
        int u = findSet(parent, g->edges[i].src);
        int v = findSet(parent, g->edges[i].dest);
        
        if(u == v)
            return 1;
        Union(u, v, parent);
    }
	return 0;
}

int main(void) {
    int v, e, i, src, dest;
    
    printf("Enter number of vertices and number of edges in graph: ");
    scanf("%d %d", &v, &e);
    
    Graph *graph = createGraph(v,e);
    
    printf("Enter end-points of %d edges: ",e);
    
    for(i=0; i<e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest, i);
    }
    
    if(isCycle(graph))
        printf("Cycle found!\n");
    else
        printf("No cycle found!\n");
	return 0;
}


