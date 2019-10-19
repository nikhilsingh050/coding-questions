//Do inorder traversal and store the data in an array.
//if the array is sorted -> it is BST

//Time Complexity: O(n);
//Space Complexity: O(n) + O(n) of stack

void inorder(TreeNode* root, vector<int> &a)
{
    if(root==NULL)
        return;

    inorder(root->left,a);
    a.push_back(root->val);
    inorder(root->right,a);
}

bool isValidBST(TreeNode* root) {

    if(root==NULL)
        return true;
    vector<int> a;

    inorder(root,a);

    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]>=a[i+1])
            return false;
    }
    return true;
}




/////////////////////////////////////////////////////////////


//Do inorder traversal and keep track of previous node.
//prev will always be less in inorder traversal

//Time Complexity: O(n)
//Space Complexity: O(1) + O(n) recursion stack size


bool isValidBSTUtil(TreeNode* root, TreeNode *&prev) {
    if(root==NULL)
        return true;

    if(isValidBST(root->left)==false)
        return false;

    if(prev!=NULL && prev->val >= root->val)
        return false;

    //keep track of previous node
    prev=root;

    return isValidBST(root->right);
}


bool isValidBST(TreeNode* root)
{
    TreeNode *prev=NULL;
    return isValidBSTUtil(root,prev);
}





//////////////////////////////////////////////////////////////

//keep track of valid minimum and maximum values for a node
//narrow down the range as you go top-down


bool isValidBSTUtil(TreeNode* root, int min, int max)
{
    if(root==NULL)
        return true;

    //if current node not in valid range
    if(root->val <min || root->val> max)
        return false;

    return isValidBSTUtil(root->left, min, root->val-1) &&
            isValidBSTUtil(root->right, root->val+1,max);
}


bool isValidBST(TreeNode* root)
{
    return isValidBSTUtil(root,INT_MIN,INT_MAX);
}
