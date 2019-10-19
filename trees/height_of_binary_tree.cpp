//Maximum height of a binary tree

int maxDepth(TreeNode* root)
{
    if(root==NULL)
        return -1;

    return 1+max(maxDepth(root->left),maxDepth(root->right));
}



///////////////////////////////////////////////////////////////

//easy to understand

int maxDepth(TreeNode* root)
{
    //height of NULL is -1 so that height of child node will be 0
    if(root==NULL)
        return -1;

    //height of left sub-tree
    int l = maxDepth(root->left);

    //height of right sub tree
    int r = maxDepth(root->right);

    // 1 + max of left and right tree height
    return 1+max(l,r);
}
