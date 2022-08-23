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
    int recur(TreeNode* root,int& sum,int dir)
    {
        if(root==NULL)
            return  1;
        bool a=recur(root->left,sum,1);
        bool b=recur(root->right,sum,0);
        if(a==1 && b==1 && dir==1)
        {
            sum=sum+root->val;
        }
        return 0;
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum=0;
        int dir=0;
        recur(root,sum,dir);
        return sum;
        
    }
};