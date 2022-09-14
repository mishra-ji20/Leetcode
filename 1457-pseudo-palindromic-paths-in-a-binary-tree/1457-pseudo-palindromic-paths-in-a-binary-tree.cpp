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
    int dfs(TreeNode* root,unordered_map<int,int>&mp,int &ans)
    {
        if(root==NULL)
        {
            return 1;
        }
        mp[root->val]++;
        int a= dfs(root->left,mp,ans);
        int b=dfs(root->right,mp,ans);
        if(a&b)
        {
            int flag=0;
            for(auto it:mp)
            {
                if(it.second%2)flag++;
            }
            if(flag<2)
                ans++;
        }
        mp[root->val]--;
        return 0;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mp;
        int ans=0;
        dfs(root,mp,ans);
        return ans;
        
    }
};