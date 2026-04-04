#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m, i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Array of pointers (Adjacency List)
    struct Node* adj[n];

    // Initialize all lists as empty
    for (i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add v to u's list
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Add u to v's list (for undirected graph)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for (i = 0; i < n; i++) {
        printf("%d -> ", i);

        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
