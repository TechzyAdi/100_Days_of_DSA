struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    // If both nodes are smaller → go left
    if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // If both nodes are greater → go right
    if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // Split point → this is LCA
    return root;
}
