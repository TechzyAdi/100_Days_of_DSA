int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;

    while (front < rear) {
        int size = rear - front;

        result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* temp = queue[front++];

            result[level][i] = temp->val;

            if (temp->left)
                queue[rear++] = temp->left;

            if (temp->right)
                queue[rear++] = temp->right;
        }

        level++;
    }

    *returnSize = level;
    return result;
}
