#include <stdio.h>

#define INF 1000000000

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Edge edges[m];

    printf("\nEnter edges (format: source destination weight)\n");
    for (int i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("\nEnter source vertex: ");
    scanf("%d", &src);

    int dist[n + 1];

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Bellman-Ford Algorithm
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for Negative Cycle
    int negativeCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            negativeCycle = 1;
            break;
        }
    }

    // Output
    printf("\n----- RESULT -----\n");

    if (negativeCycle) {
        printf("NEGATIVE WEIGHT CYCLE DETECTED!\n");
    } else {
        printf("Shortest distances from source %d:\n", src);

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF)
                printf("Vertex %d : INF\n", i);
            else
                printf("Vertex %d : %d\n", i, dist[i]);
        }
    }

    return 0;
}
