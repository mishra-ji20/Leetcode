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
    int dfs(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return 0;
        int a=dfs(root->left,ans);
        int b=dfs(root->right,ans);
       int res=max(max(a+b+root->val,a+root->val),max(b+root->val,root->val));
        ans=max(ans,res);
            return max(a+root->val,max(b+root->val,root->val));
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
        
    }
};