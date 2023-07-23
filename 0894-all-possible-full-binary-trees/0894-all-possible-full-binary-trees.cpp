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
    
    void create(vector<TreeNode*> &ans,vector<TreeNode*> &left,vector<TreeNode*> &right)
    {
        for(int i=0;i<left.size();i++)
        {
            for(int j=0;j<right.size();j++)
            {
                TreeNode *head=new TreeNode(0,left[i],right[j]);
                ans.push_back(head);
            }
        }
    }
    map<int,vector<TreeNode*>>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(dp[n].size()>0)
            return dp[n];
        if(n==1)
        {
            TreeNode* head=new TreeNode(0,NULL,NULL);
            dp[1].push_back(head);
            return dp[1];
        }
        vector<TreeNode*>ans;
        for(int i=1;i<=n-1;i=i+2)
        {
            vector<TreeNode*>left=allPossibleFBT(n-1-i);  
            vector<TreeNode*>right=allPossibleFBT(i);
            create(ans,left,right);
        }
        dp[n]=ans;
        return ans;
        
    }
};