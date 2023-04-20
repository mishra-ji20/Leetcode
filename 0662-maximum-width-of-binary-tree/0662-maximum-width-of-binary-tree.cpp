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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        long long ans=LLONG_MIN;
       
        while(!q.empty())
        {
             long long int ma=LLONG_MIN,mi=LLONG_MAX;
            int a=q.size();
            int flag=0;
            int ref=0;
            while(a--)
            {
                TreeNode* temp=q.front().first;
                long long int count=q.front().second;
                ma=max(ma,count);
                mi=min(mi,count);
                q.pop();
                if(temp->left)
                {
                    if(flag==0)
                    {
                        ref=count;
                        flag=1;
                    }
                    q.push({temp->left,2*(count-ref)+0});
                 
                }
                if(temp->right)
                {
                    if(flag==0)
                    {
                        ref=count;
                        flag=1;
                    }                   
                    q.push({temp->right,2*(count-ref)+1});
                }
            }
            ans=max(ans,ma-mi+1);
        }
        return ans;
        
        
    }
};