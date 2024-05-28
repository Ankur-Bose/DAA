#include <stdio.h>

#define MAX 100

void dfs(int graph[MAX][MAX], int visited[MAX], int node, int n) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, n);
        }
    }
}

int main() {
    int graph[MAX][MAX], visited[MAX] = {0};
    int n, startNode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter start node: ");
    scanf("%d", &startNode);

    printf("DFS Traversal: ");
    dfs(graph, visited, startNode, n);
    printf("\n");

    return 0;
}
