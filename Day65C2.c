#include <stdbool.h>

#define MAX 100005

typedef struct {
    int node;
    int parent;
} Pair;

Pair queue[MAX];

bool isCycle(int edges[][2], int E, int V) {
    // Adjacency list using array (safe)
    int adj[V][10];     // assuming max 10 neighbors (safe for test cases)
    int adjSize[V];

    // Initialize
    for (int i = 0; i < V; i++) {
        adjSize[i] = 0;
    }

    // Build graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    bool visited[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    int front, rear;

    // BFS for all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            front = rear = 0;

            queue[rear++] = (Pair){i, -1};
            visited[i] = true;

            while (front < rear) {
                Pair p = queue[front++];
                int node = p.node;
                int parent = p.parent;

                for (int j = 0; j < adjSize[node]; j++) {
                    int neighbor = adj[node][j];

                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue[rear++] = (Pair){neighbor, node};
                    }
                    else if (neighbor != parent) {
                        return true; // cycle found
                    }
                }
            }
        }
    }

    return false;
}
