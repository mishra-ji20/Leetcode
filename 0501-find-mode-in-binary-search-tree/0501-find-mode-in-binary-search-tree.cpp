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
    void recur(TreeNode* root,unordered_map<int,int>&mp)
    {
        if(root==NULL)
            return ;
        recur(root->left,mp);
        mp[root->val]++;
        recur(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        int prev=INT_MIN;
        unordered_map<int,int>mp;
        recur(root,mp);
        vector<int>ans;
        int res=0;
        for(auto it :mp)
        {
            res=max(res,it.second);
        }
        for(auto it:mp)
        {
            if(it.second==res)
            {
                ans.push_back(it.first);
            }
            
        }
        return ans;
        
    }
};