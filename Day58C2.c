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
struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd,
                       int* map) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root value
    int rootVal = preorder[preStart];
    struct TreeNode* root = createNode(rootVal);

    // Find index in inorder using map
    int inIndex = map[rootVal + 3000];  // offset for negative values

    int leftSize = inIndex - inStart;

    // Build left subtree
    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, inIndex - 1, map);

    // Build right subtree
    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, inIndex + 1, inEnd, map);

    return root;
}

// Main function
struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {

    // Map value → index
    int* map = (int*)malloc(6001 * sizeof(int)); // range -3000 to 3000

    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    return build(preorder, 0, preorderSize - 1,
                 inorder, 0, inorderSize - 1, map);
}
