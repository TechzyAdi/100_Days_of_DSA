#include <stdio.h>

#define SIZE 100
#define INF 999999

int graph[SIZE][SIZE];
int visited[SIZE];

int main() {
    int n, m;
    int u, v, w;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    int totalCost = 0;
    visited[1] = 1; // start from node 1

    printf("\nEdges in MST:\n");

    for (int k = 1; k < n; k++) {
        int min = INF;
        int x = -1, y = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            printf("%d - %d (weight %d)\n", x, y, min);
            totalCost += min;
            visited[y] = 1;
        }
    }

    printf("\nTotal weight of MST: %d\n", totalCost);

    return 0;
}
