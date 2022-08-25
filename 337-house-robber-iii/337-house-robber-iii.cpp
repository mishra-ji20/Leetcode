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
    vector<unsigned int>dfs(TreeNode* root)
    {
        vector<unsigned int>ans(3,0);
        if(root==NULL)
            return ans;
        vector< unsigned int>a=dfs(root->left);
        vector<unsigned int>b=dfs(root->right);
        ans[0]=max(max(a[0]+b[0],a[1]+b[1]+root->val),a[0]-a[2]+b[0]-b[2]+root->val);
        ans[1]=a[0]+b[0];
        ans[2]=root->val;
        return ans;
    }
    int rob(TreeNode* root) {
        vector<unsigned int>res=dfs(root);
        return res[0];
        
    }
};