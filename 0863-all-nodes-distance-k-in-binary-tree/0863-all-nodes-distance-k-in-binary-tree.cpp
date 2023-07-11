/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(vector<int> &ans,TreeNode *root,TreeNode* target,bool &flagdown,int &k,int curr){
        if(root==NULL)
            return 0;
        if(root==target){
            flagdown=1;
        }
        int l=0,r=0;
        l=dfs(ans,root->left,target,flagdown,k,curr+flagdown);
        if(l)
        r=dfs(ans,root->right,target,flagdown,k,l+flagdown);
        else
        r=dfs(ans,root->right,target,flagdown,k,curr+flagdown);
        if(r)
        l=dfs(ans,root->left,target,flagdown,k,r+flagdown);
        if(curr==k || max(l,r)==k)
            ans.push_back(root->val);
        if(root==target || max(l,r))
            return 1+max(l,r);
        return 0;
        
       
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(k==0){
            ans.push_back(target->val);
            return ans;
        }
        int curr=0;
        bool flag=0;
        int flagup=-1;
        dfs(ans,root,target,flag,k,curr);
        return ans;
        
        
    }
};