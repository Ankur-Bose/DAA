#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int graph[MAX][MAX], int startNode, int n) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX], n, startNode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter start node: ");
    scanf("%d", &startNode);

    printf("BFS Traversal: ");
    bfs(graph, startNode, n);

    return 0;
}
