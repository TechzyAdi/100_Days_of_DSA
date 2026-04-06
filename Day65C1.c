#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS to detect cycle
int dfs(int node, int parent) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int v = temp->vertex;

        // If not visited → go deeper
        if (!visited[v]) {
            if (dfs(v, node))
                return 1;
        }
        // If visited and not parent → cycle
        else if (v != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Check cycle in all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES (Cycle exists)\n");
                return 0;
            }
        }
    }

    printf("NO (No cycle)\n");
    return 0;
}
