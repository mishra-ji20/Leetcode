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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int a=q.size();
            double n=a;
            double sum=0;
            while(a--)
            {
                TreeNode* temp=q.front();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                sum=sum+(double)temp->val;
                q.pop();
            }
            ans.push_back(sum/n);
            
        }
        return ans;
        
    }
};