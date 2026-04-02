#include <stdio.h>

int main() {
    int n, m, i, u, v;
    int choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int adj[n][n];

    // Initialize matrix with 0
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter 1 for Directed graph, 0 for Undirected: ");
    scanf("%d", &choice);

    printf("Enter edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if (choice == 0) {
            adj[v][u] = 1; // For undirected
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
