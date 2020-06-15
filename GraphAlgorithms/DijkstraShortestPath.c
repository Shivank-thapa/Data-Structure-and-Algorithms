#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int minDistance(int result[], bool visited[], int V) {
    int i, min=INT_MAX, minIdx;
    for (i=0; i<V; i++){
        if (!visited[i] && result[i] <= min) {
            min=result[i];
            minIdx = i;
        }
    }   
   return minIdx;
}

void printResult(int result[], int V) {
    int i;
    printf("Vertex      Distance\n");
    for(i=0; i<V; i++) {
        printf("%d      %d\n",i, result[i]);
    }
}

void dijkstra(int V, int graph[V][V], int src) {
    int i,j;
    int result[V];
    bool visited[V];
    
    for(i=0; i<V; i++) {
        result[i] = INT_MAX;
        visited[i] = false;
    }
    
    result[src] = 0;
    for(i=0; i<V-1; i++) {
        int u = minDistance(result, visited, V);
        visited[u] = true;
        for(j=0; j<V; j++) {
            if(!visited[j] && graph[u][j] && result[u] != INT_MAX && result[j] > result[u]+graph[u][j])
                result[j] = result[u] + graph[u][j];
        }
    }
    printResult(result, V);
}

int main(void) {
	int i, j, v, src;
	printf("Enter number of vertices: ");
	scanf("%d", &v);
	int graph[v][v];
	printf("Enter %dX%d matrix for graph edge weights\n", v, v);
	for(i=0; i<v; i++)
	    for(j=0; j<v; j++)
	        scanf("%d",&graph[i][j]);
	printf("Enter source vertex: ");
	scanf("%d", &src);
	dijkstra(v, graph, src);
	return 0;
}


