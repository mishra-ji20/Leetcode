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
    void dfs(TreeNode* root,int curr_max,int &count)
    {
      if(root==NULL)
          return;
        curr_max=max(curr_max,root->val);
        dfs(root->left,curr_max,count);
         dfs(root->right,curr_max,count);
        if(curr_max==root->val)
            count++;
        
        
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int curr_max=INT_MIN;
        dfs(root,curr_max,count);
        return count;
    }
};