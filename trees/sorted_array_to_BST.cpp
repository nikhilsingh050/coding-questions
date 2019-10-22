TreeNode* growTree(vector<int> &nums, int i, int j)
{
    if(i>j)
        return NULL;

    int mid = (i+j)/2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = growTree(nums,i,mid-1);
    root->right = growTree(nums,mid+1,j);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return growTree(nums,0,nums.size()-1);
}
