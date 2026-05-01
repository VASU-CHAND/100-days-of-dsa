#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX], n;

// Function to find minimum key vertex not yet included in MST
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST() {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;   // Start from node 0
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate total weight
    int total = 0;
    for (int i = 1; i < n; i++) {
        total += graph[i][parent[i]];
    }

    return total;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; // convert to 0-based indexing
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", primMST());

    return 0;
}