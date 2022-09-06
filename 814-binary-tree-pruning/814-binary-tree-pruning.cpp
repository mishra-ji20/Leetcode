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
    int dfs(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int a=dfs(root->left);
        int b=dfs(root->right);
        if(a==0)
            root->left=NULL;
        if(b==0)
            root->right=NULL;
        return ((a|b)|root->val);
    }
    TreeNode* pruneTree(TreeNode* root) {
        int a=dfs(root);
        if(a==0)
            root=NULL;
        return root;
        
    }
};