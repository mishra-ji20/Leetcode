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
    void create(vector<TreeNode*> &temp,vector<TreeNode*> &left,vector<TreeNode*> &right)
    {
        for(int i=0;i<left.size();i++)
        {
            for(int j=0;j<right.size();j++)
            {
                temp.push_back(new TreeNode(0,left[i],right[j]));
            }
        }
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>>dp((n/2+1));
        TreeNode* head=new TreeNode(0,NULL,NULL);
        dp[0].push_back(head);
        if(n==1)
            return dp[n/2];
        for(int i=3;i<=n;i=i+2)
        {
            vector<TreeNode*>temp;
            for(int j=1;j<=i-1;j=j+2)
            {
                create(temp,dp[j/2],dp[(i-1-j)/2]);
            }
            // cout<<temp.size();
            dp[i/2]=temp;
            
        }
        return dp[n/2];
        
        
    }
};