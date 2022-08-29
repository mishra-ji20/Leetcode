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
    TreeNode* dfs(vector<int>&nums,int l,int r)
    {
        if(l>r)
            return NULL;
        int mind=l;
        for(int i=l+1;i<=r;i++)
        {
            mind=nums[mind]<nums[i]?i:mind;
        }
        TreeNode* temp=new TreeNode(nums[mind]);
        temp->left=dfs(nums,l,mind-1);
        temp->right=dfs(nums,mind+1,r);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode * ans;
       ans=dfs(nums,0,nums.size()-1);
        return ans;
    }
};