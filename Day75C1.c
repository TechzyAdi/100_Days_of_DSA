#define SIZE 100

int isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[SIZE];

    // Initialize all nodes as uncolored
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    int queue[SIZE];

    // Handle disconnected graph
    for (int start = 0; start < graphSize; start++) {

        if (color[start] != -1)
            continue;

        int front = 0, rear = 0;
        queue[rear++] = start;
        color[start] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int i = 0; i < graphColSize[node]; i++) {
                int neighbor = graph[node][i];

                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                else if (color[neighbor] == color[node]) {
                    return 0; // false
                }
            }
        }
    }

    return 1; // true
}
