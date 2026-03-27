#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int* rightSideView(struct TreeNode* root, int* returnSize) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    int* result = (int*)malloc(1000 * sizeof(int));
    int count = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            // 🔥 Last node of level
            if (i == size - 1) {
                result[count++] = curr->val;
            }

            if (curr->left)
                queue[rear++] = curr->left;
            if (curr->right)
                queue[rear++] = curr->right;
        }
    }

    *returnSize = count;
    return result;
}
