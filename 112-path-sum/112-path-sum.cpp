/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    bool path(TreeNode*root,int t,int sum)
    {
        if(root==NULL)
            return 0;
        sum=sum+root->val;
        if(root->right==NULL && root->left==NULL && sum==t)
            ans=1;
         bool a=path(root->right,t,sum);
        bool b=path(root->left,t,sum);
       return a&b;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        path(root,targetSum,0);
        return ans;
        
        
    }
};