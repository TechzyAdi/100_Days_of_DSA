#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate height
int height(struct Node* root) {
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    struct Node* nodes[n];

    printf("Enter level order traversal (-1 for NULL):\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Create nodes
    for(int i = 0; i < n; i++) {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Connect nodes
    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    int h = height(nodes[0]);

    printf("Height of the tree: %d", h);

    return 0;
}
