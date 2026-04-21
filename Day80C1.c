#include <stdio.h>

#define SIZE 100
#define INF 999999

int main() {
    int n;
    int dist[SIZE][SIZE];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (-1 for no edge):\n");

    // Input and initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            if (dist[i][j] == -1 && i != j)
                dist[i][j] = INF;
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }

    // Output result
    printf("\nShortest distance matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);

        }
        printf("\n");
    }

    return 0;
}
