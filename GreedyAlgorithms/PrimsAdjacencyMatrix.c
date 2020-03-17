#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int findMinKey(int key[], bool inMST[], int V) {
    int i, min = INT_MAX, minIndex;
    for(i=0; i<V; i++) {
        if(!inMST[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primsMST(int V, int graph[V][V]) {
    int i, j, parent[V], key[V];
    bool inMST[V];

    for(i=0; i<V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(i=1; i<V; i++) {
        int minKeyIndex = findMinKey(key, inMST, V);

        inMST[minKeyIndex] = true;
        for(j=0; j<V; j++) {
            if(graph[minKeyIndex][j] && !inMST[j] && graph[minKeyIndex][j] < key[j]) {
                parent[j] = minKeyIndex;
                key[j] = graph[minKeyIndex][j];
            }
        }
    }

    //printing the MST
    printf(" EDGE    WEIGHT\n");
    for(i=1; i<V; i++) {
        printf("%d -- %d      %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main(void){
    int V,i,j;
    printf("Enter number of vertices in graph: ");
    scanf("%d",&V);
    int graph[V][V];
    printf("Enter vertices for %d X %d graph: ",V,V);
    for(i=0; i<V; i++) {
        for(j=0; j<V; j++) {
           scanf("%d", &graph[i][j]);
        }
    }
    primsMST(V, graph);
    return 0;
}
