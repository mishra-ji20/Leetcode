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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res=INT_MIN;
        int sol=0;
        int count=1;
        while(!q.empty())
        {
            int s=q.size();
            long ans=0;
            while(s--)
            {
                 auto a=q.front();
                ans=ans+a->val;
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
                q.pop();
            }
            if(res<ans)
            {
                res=ans;
               sol=count; 
            }
            count++;
        }
        return sol;
        
    }
};