//Convert a given sorted array to BST.

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







/////////////////////////////////////////////////////////////////////////

//Noob Approach: First Attempt

/*
    void growTree(TreeNode* head, vector<int> &nums, int i, int j)
    {
        int mid = (i+j)/2;
        head->val=nums[mid];

        //for single element
        if(i==j)
        {
            head->left=NULL;
            head->right=NULL;
            return;
        }

        //if left child exists
        if(i!=mid)
        {
            head->left=new TreeNode(0);;
            growTree(head->left, nums, i, mid-1);
        }
        else
            head->left=NULL;

        //if right child exists
        if(j!=mid)
        {
            head->right=new TreeNode(0);;
            growTree(head->right, nums, mid+1, j);
        }
        else
            head->right=NULL;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        TreeNode *head= new TreeNode(0);
        growTree(head,nums,0,nums.size()-1);
        return head;
    }
*/
