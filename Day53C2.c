#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Queue
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    // Result array
    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    enqueue:
    queue[rear++] = root;

    int levelCount = 0;

    while (front < rear) {
        int size = rear - front;

        // Allocate memory for this level
        result[levelCount] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[levelCount] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            result[levelCount][i] = curr->val;

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }

        levelCount++;
    }

    *returnSize = levelCount;
    return result;
}
