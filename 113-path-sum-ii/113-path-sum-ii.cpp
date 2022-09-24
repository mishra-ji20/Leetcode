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
    int sol(vector<vector<int>>&ans,TreeNode *root,int target,vector<int>&res,int& sum)
    {
        if(root==NULL)
            return 1;
        res.push_back(root->val);
        sum=sum+root->val;
        int a=sol(ans,root->left,target,res,sum);
        int b=sol(ans,root->right,target,res,sum);
        if(a==1 && b==1 && sum==target)
            ans.push_back(res);
        res.pop_back();
        sum=sum-root->val;
        return 0;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>res;
        int sum=0;
        sol(ans,root,targetSum,res,sum);
        return ans;
        
    }
};