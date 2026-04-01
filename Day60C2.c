int cameras = 0;

// Function to decide camera placement
int solve(struct TreeNode* root) {
    if (root == NULL)
        return 0; // Covered

    int left = solve(root->left);
    int right = solve(root->right);

    // If any child is NOT covered
    if (left == -1 || right == -1) {
        cameras++;
        return 1; // Has camera
    }

    // If any child has camera
    if (left == 1 || right == 1)
        return 0; // Covered

    return -1; // Not covered
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0; // reset for safety

    if (solve(root) == -1)
        cameras++;

    return cameras;
}
