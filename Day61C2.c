void dfs(int city, int n, int isConnected[n][n], int visited[]) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(i, n, isConnected, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[n];
    int provinces = 0;

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // DFS
            int stack[200], top = -1;
            stack[++top] = i;
            visited[i] = 1;

            while (top != -1) {
                int curr = stack[top--];

                for (int j = 0; j < n; j++) {
                    if (isConnected[curr][j] == 1 && !visited[j]) {
                        stack[++top] = j;
                        visited[j] = 1;
                    }
                }
            }

            provinces++;
        }
    }

    return provinces;
}
