#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    queue[rear++] = root;

    int level = 0;

    while (front < rear) {
        int size = rear - front;

        result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            // 🔥 Zigzag logic
            int index;
            if (level % 2 == 0)
                index = i;                 // left → right
            else
                index = size - 1 - i;      // right → left

            result[level][index] = curr->val;

            if (curr->left)
                queue[rear++] = curr->left;
            if (curr->right)
                queue[rear++] = curr->right;
        }

        level++;
    }

    *returnSize = level;
    return result;
}
