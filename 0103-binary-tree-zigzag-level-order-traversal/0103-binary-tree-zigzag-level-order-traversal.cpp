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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int count=0;
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>temp1;
            int n =q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                temp1.push_back(temp->val);
                 q.pop();
            }
            if(count%2)
            {
                reverse(temp1.begin(),temp1.end());
            }
            count++;
            res.push_back(temp1);
        }
        return res;
        
    }
};