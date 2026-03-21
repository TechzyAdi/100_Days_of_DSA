struct TreeNode* insertIntoBST(struct TreeNode* root, int val) 
{
    // If tree is empty, create new node
    if(root == NULL)
    {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Traverse BST
    if(val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}
