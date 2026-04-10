#include <stdlib.h>
#include <limits.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    
    // adjacency matrix
    int graph[101][101];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // fill graph
    for(int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }

    int dist[101];
    int visited[101] = {0};

    // initialize distances
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[k] = 0;

    // Dijkstra
    for(int count = 1; count <= n; count++) {
        int u = -1, min = INT_MAX;

        // find min distance node
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INT_MAX && !visited[v]) {
                if(dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // find max distance
    int maxTime = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX)
            return -1;
        if(dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}
