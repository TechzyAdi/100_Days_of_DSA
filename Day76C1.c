#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

// DFS function
void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    int u, v;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected graph
    }

    int count = 0;

    // Count components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, n);
            count++;
        }
    }

    printf("Number of connected components: %d\n", count);

    return 0;
}
