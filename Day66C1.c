#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool dfs(int node, int V, int adj[V][V], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i] && dfs(i, V, adj, visited, recStack))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool isCycle(int V, int edges[][2], int E) {
    int adj[V][V];

    // Initialize
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Directed graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
    }

    bool visited[V], recStack[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return true;
        }
    }

    return false;
}

int main() {
    int V = 4, E = 4;
    int edges[][2] = {{0,1}, {1,2}, {2,0}, {2,3}};

    if (isCycle(V, edges, E))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
