#include <stdio.h>
#include <stdbool.h>

#define V 4   // number of vertices

bool dfs(int graph[V][V], int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(graph, i, visited, recStack))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

bool hasCycle(int graph[V][V]) {
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0}  // cycle here
    };

    if (hasCycle(graph))
        printf("YES, Cycle Exists\n");
    else
        printf("NO Cycle\n");

    return 0;
}