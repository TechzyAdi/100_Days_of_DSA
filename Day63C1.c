#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int v, int n, int adj[MAX][MAX]) {
    printf("%d ", v);      // visit node
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n, adj);
        }
    }
}

int main() {
    int n, i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    // Initialize visited
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(s, n, adj);

    return 0;
}
