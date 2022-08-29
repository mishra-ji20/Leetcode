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
    int dfs(TreeNode* root,int target)
    {
        if(root==NULL)
            return 1;
        int a=dfs(root->left,target);
        int b=dfs(root->right,target);
        if(a==2){
            root->left=NULL;
            a=1;
        }
        if(b==2){
            root->right=NULL;
            b=1;
        }
        if(a==1 && b==1 && root->val==target)
            return 2;
        return 0;
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
       TreeNode* nr=new TreeNode(-1,root,NULL);
        dfs(nr,target);
        return nr->left;
        
    }
};