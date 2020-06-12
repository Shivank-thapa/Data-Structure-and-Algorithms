#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int src;
    int dest;
    int weight;
}Edge;

typedef struct Graph {
    int V;
    int E;
    Edge *edges;
}Graph;

Graph *createGraph(int v, int e) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = v;
    g->E = e;
    g->edges = (Edge *)malloc(e * sizeof(Edge));
    
    return g;
}

void addEdge(int i, int s, int d, int w, Graph *g) {
    g->edges[i].src = s;
    g->edges[i].dest = d;
    g->edges[i].weight = w;
}

int findSet(int parent[], int x) {
    if(parent[x] == -1)
        return x;
    return findSet(parent, parent[x]);
}

void Union(int parent[], int x, int y) {
    int xSet = findSet(parent, x);
    int ySet = findSet(parent, y);
    
    if(x != y) {
        parent[xSet] = ySet;
    }
}

int myComparator(const void *a, const void *b) {
    Edge *u = (Edge *)a;
    Edge *v = (Edge *)b;
    return u->weight > v->weight;
}

void kruskalMST(Graph *g) {
    int i,k=0;
    Edge result[g->V];
    
    qsort(g->edges, g->E, sizeof(g->edges[0]), myComparator);
    int *parent = (int *)malloc(g->V * sizeof(int));
    memset(parent, -1, sizeof(int)*g->V);
    
    for(i=0; i<g->E; i++) {
        Edge e = g->edges[i];
        int x = findSet(parent, e.src);
        int y = findSet(parent, e.dest);
        
        if(x != y) {
            result[k++] = e;
            Union(parent, x, y);
        }
    }
    
    printf("Edges present in MST are: \n");
    printf("S  D        w\n");
    for(i=0; i<k; i++)
        printf("%d--%d      %d\n",result[i].src, result[i].dest, result[i].weight);
}

int main(void) {
    int v, e, i, s, d, w;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d",&v, &e);
    
    Graph *g = createGraph(v, e);
    
    printf("Enter source, destination and weight of %d edges\n",e);
    for(i=0; i<e; i++) {
        scanf("%d %d %d", &s, &d, &w);
        addEdge(i, s, d, w, g);
    }
    kruskalMST(g);
	return 0;
}


