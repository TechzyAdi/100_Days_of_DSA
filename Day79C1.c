#include <stdio.h>

#define SIZE 100
#define INF 999999

int graph[SIZE][SIZE];
int dist[SIZE];
int visited[SIZE];

int main() {
    int n, m;
    int u, v, w, source;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    printf("Enter source node: ");
    scanf("%d", &source);

    // Initialize distance and visited
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int min = INF, u = -1;

        // Find minimum distance unvisited node
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update neighbors
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && graph[u][j] != INF) {
                if (dist[u] + graph[u][j] < dist[j]) {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Output distances
    printf("\nShortest distances:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}
