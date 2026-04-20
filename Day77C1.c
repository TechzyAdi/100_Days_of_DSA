#include <stdio.h>

#define SIZE 100

int graph[SIZE][SIZE];
int visited[SIZE];

// DFS function
void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    int u, v;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v format):\n");
    for (int i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1; // undirected graph
    }

    // Start DFS from node 1
    dfs(1, n);

    // Check connectivity
    int isConnected = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            isConnected = 0;
            break;
        }
    }

    printf("\nResult: ");
    if (isConnected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}
