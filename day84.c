#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n, adj);
        }
    }
}

int main() {
    int n, adj[MAX][MAX], start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(start, n, adj);

    return 0;
}