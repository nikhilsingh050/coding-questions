//Recursive Solution:

//recursive function will take two copies of the same tree as parameter
//and compare mirror nodes for two trees.

//Time Complexity: O(2n) -> O(n)
//Space Complexity: O(1) + O(2n) recursion stack size


bool sym(TreeNode *t1, TreeNode *t2)
{
    //base case
    if(t1==NULL && t2==NULL)
        return true;

    //if only one of the node is NULL -> return false
    if(t1==NULL || t2==NULL)
        return false;

    return (t1->val==t2->val) &&
            sym(t1->left,t2->right) &&
            sym(t1->right,t2->left);
}

bool isSymmetric(TreeNode* root) {
    return sym(root,root);
}




///////////////////////////////////////////////////////////////////////////

//Iterative Solution:

//Use a queue to store mirror nodes of two trees
//and check the front two nodes in queue
//if both nodes are NULL -> continue to pop and check
//if only one of the two node is NULL -> return false.

//Time Complexity: O(2n) -> O(n)
//Space Complexity: O(2n) -> O(n)

bool isSymmetric(TreeNode* root)
{
    queue<TreeNode*> q;

    q.push(root);
    q.push(root);

    TreeNode *t1,*t2;

    while(!q.empty())
    {
        t1=q.front();
        q.pop();
        t2=q.front();
        q.pop();

        //front two nodes in queue are null -> continue to pop and check
        if(t1==NULL && t2==NULL)
            continue;

        ////if only one of the node is NULL -> return false
        if(t1==NULL || t2==NULL)
            return false;

        if(t1->val != t2->val)
            return false;

        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }
    return true;
}
