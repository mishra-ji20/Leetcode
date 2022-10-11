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
    bool isCousins(TreeNode* root, int x, int y) {
        int px,dx;
        int py,dy;
        queue<TreeNode*>q;
        q.push(root);
            int d=0;
        while(!q.empty())
        {
           
            int s=q.size();
            while(s--)
            {
                 auto a=q.front();
                    q.pop();
                if(a->left)
                {
                    q.push(a->left);
                    if(a->left->val==x)
                    {
                        px=a->val;
                        dx=d;
                    }
                    if(a->left->val==y)
                    {
                        py=a->val;
                        dy=d;
                    }
                }
                if(a->right)
                {
                    q.push(a->right);
                    if(a->right->val==x)
                    {
                        px=a->val;
                        dx=d;
                    }
                    if(a->right->val==y)
                    {
                        py=a->val;
                        dy=d;
                    }
                }
            }
            d++;
        }
        if(dx==dy && px!=py)
        return true;
        return false;
    }
};