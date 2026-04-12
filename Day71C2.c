#include <limits.h>
#include <stdlib.h>

int manhattan(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    if (dx < 0) dx = -dx;

    int dy = y1 - y2;
    if (dy < 0) dy = -dy;

    return dx + dy;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    
    int minDist[pointsSize];
    int visited[pointsSize];

    // Initialize
    for (int i = 0; i < pointsSize; i++) {
        minDist[i] = INT_MAX;
        visited[i] = 0;
    }

    minDist[0] = 0;
    int totalCost = 0;

    // Prim's Algorithm
    for (int i = 0; i < pointsSize; i++) {
        int u = -1;

        // Find min node
        for (int j = 0; j < pointsSize; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        // Update distances
        for (int v = 0; v < pointsSize; v++) {
            if (!visited[v]) {
                int dist = manhattan(points[u][0], points[u][1],
                                     points[v][0], points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    return totalCost;
}
