//Problem: Store result level order traversal in a vector of vector,
//level-wise separately.

///////////////////////////////////////////////////////////////////////

//Iterative Solution:

//use a queue
//store result level wise according to the size of queue

//Time Complexity: O(n)
//Space Complexity: O(n)


vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> result;

    queue<TreeNode*> q;

    if(root!=NULL)
        q.push(root);
    TreeNode* t;

    while(!q.empty())
    {
        int n = q.size();
        vector<int> res;

        //add first n nodes of the queue to this level result
        while(n>0)
        {
            t=q.front();
            q.pop();
            res.push_back(t->val);

            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
            n--;
        }

        result.push_back(res);
    }
    return result;
}




////////////////////////////////////////////////////////////////////

//Recursive Solution:

//Each recursion call will have its level
//add the node to the level index of the result vector

//Time Complexity: O(n)
//Space Complexity: O(1) + O(n) recursion stack size


void levelOrderUtil(TreeNode* root,int level, vector<vector<int>> &result)
{
    if(root==NULL)
        return;

    if(result.size()<=level)
        result.push_back({root->val});
    else
        result[level].push_back(root->val);

    levelOrderUtil(root->left,level+1,result);
    levelOrderUtil(root->right,level+1,result);
}


vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    levelOrderUtil(root,0,result);
    return result;
}
