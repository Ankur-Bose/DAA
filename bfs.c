#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// A structure to represent an adjacency list
struct AdjList {
    struct Node* head;  // Pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of the array will be V (number of vertices in graph)
struct Graph {
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct Node* newAdjListNode(int dest) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists. Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency list of src.
    // The node is added at the beginning
    struct Node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list representation of graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct Node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// A utility function to create a queue
struct Queue {
    int items[100];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == 100 - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// BFS traversal from a given source src
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();

    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;  // Mark all vertices as not visited
    }

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        struct Node* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->dest;

            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("Breadth First Traversal starting from vertex 0:\n");
    BFS(graph, 0);

    return 0;
}
