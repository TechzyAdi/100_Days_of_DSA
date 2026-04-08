#include <stdbool.h>

// DFS
bool dfs(int node, int V, int** adj, int* adjSize, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor] && dfs(neighbor, V, adj, adjSize, visited, recStack))
            return true;
        else if (recStack[neighbor])
            return true;
    }

    recStack[node] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // Create adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    // Build graph (b → a)
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
    }

    bool visited[numCourses];
    bool recStack[numCourses];

    for (int i = 0; i < numCourses; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    // DFS for cycle detection
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, numCourses, adj, adjSize, visited, recStack))
                return false; // cycle found
        }
    }

    return true;
}
