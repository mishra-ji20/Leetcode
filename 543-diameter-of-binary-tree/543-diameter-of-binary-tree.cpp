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
    int height(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return 0;
        int a=height(root->left,ans);
        int b=height(root->right,ans);
        ans=max(ans,a+b+1);
        return max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        height(root,ans);
        return ans-1;
        
        
    }
};