#define INF 1000000000

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize,
                      int src, int dst, int k) {
    
    int dist[n];
    int temp[n];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Bellman-Ford for k+1 iterations
    for (int i = 0; i <= k; i++) {

        // Copy dist to temp
        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }

        // Relax edges
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INF && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        // Update dist
        for (int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }
    }

    // Return result
    return (dist[dst] == INF) ? -1 : dist[dst];
}
