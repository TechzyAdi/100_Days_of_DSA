#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;

// DFS function
void dfs(int node, int V) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, V);
        }
    }

    // push into stack after visiting neighbors
    stack[++top] = node;
}

// Topological Sort function
void topoSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V);
        }
    }

    // print stack in reverse order
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    int V = 6;

    // initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Example DAG
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topoSort(V);

    return 0;
}
