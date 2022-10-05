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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            root=new TreeNode(val,root,NULL);
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        int d=1;
        bool flag=0;
        while(!q.empty()){
            int s=q.size();
            if(d==depth-1)
            {
                while(s--)
                {
                    auto a=q.front();
                    a->left=new TreeNode(val,a->left,NULL);
                    a->right=new TreeNode(val,NULL,a->right);
                    q.pop();
                }
                flag=1;
            }
            if(flag)
            {
                break;
            }
            while(s--)
            {
                auto a=q.front();
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
                q.pop();
                
            }
            d++;
        }
        return root;
        
    }
};