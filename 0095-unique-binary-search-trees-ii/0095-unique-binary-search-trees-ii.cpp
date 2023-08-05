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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>>dp(n+1,vector<vector<TreeNode*>>(n+1));
        dp[0][0].push_back(NULL);
        for(int i=1;i<=n;i++)
        {
            TreeNode* root=new TreeNode(i,NULL,NULL);
            dp[i][i].push_back(root);   
        }
        function<vector<TreeNode*>(int l,int r)>memoization =[&](int l,int r)->vector<TreeNode*>{
            if(l>r)
                return dp[0][0];
            
            // cout<<l<<' '<<r<<endl;
            if(l==r)
                return dp[l][r];
            
            if(dp[l][r].size())
                return dp[l][r];
            vector<TreeNode*>ans;
            for(int a=l;a<=r;a++)
            {
                vector<TreeNode*> right=memoization(a+1,r);
                // cout<<a<<endl;
                vector<TreeNode*> left=memoization(l,a-1);
                // cout<<left.size()<<" "<<a<<endl;
                for(int i=0;i<right.size();i++)
                {
                    for(int j=0;j<left.size();j++)
                    {
                        TreeNode* root=new TreeNode(a);
                        root->left=left[j];
                        root->right=right[i];
                        ans.push_back(root);
                    }
                }
            }
           
            dp[l][r]=ans;
            return dp[l][r];
            
        };
        return memoization(1,n); 
        
        
    }
};