/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

#define MAX 101

struct Node* visited[MAX];

// Function to clone graph using DFS
struct Node* clone(struct Node* node) {
    if (node == NULL)
        return NULL;

    // If already cloned, return it
    if (visited[node->val] != NULL)
        return visited[node->val];

    // Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = node->val;
    newNode->numNeighbors = node->numNeighbors;

    // Allocate memory for neighbors
    newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Mark as visited (store clone)
    visited[node->val] = newNode;

    // Clone all neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        newNode->neighbors[i] = clone(node->neighbors[i]);
    }

    return newNode;
}

// Main function required by platform
struct Node* cloneGraph(struct Node* node) {
    // Initialize visited array
    for (int i = 0; i < MAX; i++) {
        visited[i] = NULL;
    }

    return clone(node);
}
