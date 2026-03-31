#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper function
struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int* postIndex,
                       int* map) {

    if (inStart > inEnd)
        return NULL;

    // Root from postorder
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    // Find index in inorder
    int inIndex = map[rootVal + 3000];

    // 🔥 Build right first
    root->right = build(inorder, inIndex + 1, inEnd,
                        postorder, postIndex, map);

    root->left = build(inorder, inStart, inIndex - 1,
                       postorder, postIndex, map);

    return root;
}

// Main function
struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {

    // Map value → index
    int* map = (int*)malloc(6001 * sizeof(int));

    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    int postIndex = postorderSize - 1;

    return build(inorder, 0, inorderSize - 1,
                 postorder, &postIndex, map);
}
