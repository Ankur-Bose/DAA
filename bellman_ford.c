#include <stdio.h>
#include <limits.h>

#define V 4

void printArr(int dist[], int n) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(int graph[V][V], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return; 
            }
        }
    }

    printArr(dist, V);
}

int main() {
    int graph[V][V] = {
        {0,4,5,0},
        {0,0,0,7},
        {0,7,0,0},
        {0,0,-15,0}
    };

    BellmanFord(graph, 0);

    return 0;
}
