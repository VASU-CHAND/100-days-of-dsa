#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int n;

// Queue implementation
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Kahn's Algorithm
void topologicalSort() {
    int i, j;
    
    // Step 1: Calculate indegree
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Enqueue nodes with indegree 0
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("Topological Order: ");

    int count = 0;

    // Step 3: Process queue
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of adjacent nodes
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 4: Check cycle
    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}