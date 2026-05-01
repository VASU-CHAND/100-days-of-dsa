#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex, weight;
    struct Node* next;
};

// Min Heap Node
struct HeapNode {
    int vertex, dist;
};

// Graph
struct Node* adj[MAX];

// Distance array
int dist[MAX];

// Function to create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra Algorithm
void dijkstra(int V, int src) {
    int visited[MAX] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u = -1;

        // Find minimum distance vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        // Update neighbors
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
            temp = temp->next;
        }
    }
}

// Print result
void printDistances(int V) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Driver code
int main() {
    int V = 5;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(2, 3, 4);

    dijkstra(V, 0);
    printDistances(V);

    return 0;
}