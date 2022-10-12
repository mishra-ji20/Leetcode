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
    bool search(TreeNode* root,TreeNode* target,vector<TreeNode*>&mp)
    {
        if(root==NULL)
            return 0 ;
        if(root==target)
        {
            return 1;
        }
        bool a=search(root->left,target,mp);
        bool b=search(root->right,target,mp);
        if(a==1)
        {
            mp.push_back(root);
            root->left=NULL;
            return 1;
        }
         if(b==1)
        {
            mp.push_back(root);
            root->right=NULL;
             return 1;
        }
        return 0;
            
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<pair<TreeNode*,int>>q;
       vector<TreeNode*> mp;
        if(target==root)
        {
            q.push({root,0});
        }
        else
        {
            search(root,target,mp);
            q.push({target,0});
            for(int i=0;i<mp.size();i++)
            {
                q.push({mp[i],i+1});
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            auto a=q.front();
            q.pop();
            // cout<<a.first->val<<" "<<a.second<<"  ";
            if(a.second==k)
                ans.push_back(a.first->val);
            if(a.first->left)q.push({a.first->left,a.second+1});
            if(a.first->right)q.push({a.first->right,a.second+1});
            
        }
        return ans;           
    }
};