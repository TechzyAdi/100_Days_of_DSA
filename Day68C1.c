#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int V = 6;

    int adj[MAX][MAX] = {0};

    // Example DAG
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    int indegree[MAX] = {0};

    // Step 1: Calculate indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j])
                indegree[j]++;
        }
    }

    // Step 2: Queue
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    // Step 3: Topological sort
    int result[MAX], index = 0;

    while (front < rear) {
        int node = queue[front++];
        result[index++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // Step 4: Print result
    if (index != V) {
        printf("Cycle exists! No Topological Order\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < V; i++)
            printf("%d ", result[i]);
    }

    return 0;
}
