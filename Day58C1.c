#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Find index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // Pick current root
    struct Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    // If single node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, root->data);

    // Build left and right
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    printf("Enter inorder:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Postorder Traversal:\n");
    postorder(root);

    return 0;
}
