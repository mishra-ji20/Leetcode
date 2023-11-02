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
    pair<int,int> dfs(TreeNode *root, int& count){
        if(root==NULL)
            return {0,0};
        auto sumRight=dfs(root->right,count);
        auto sumLeft=dfs(root->left,count);
        
        // cout<<sumLeft.first<<" "<<sumRight.first<<" "<<root->val<<" "<<(sumLeft.second+sumRight.second+1)<<endl;
        
        if(((sumLeft.first+sumRight.first+root->val)/(sumLeft.second+sumRight.second+1))==root->val){
            count+=1;
        }
        // cout<<root->val<<" "<<nodeCount<<endl;
        return {sumLeft.first+sumRight.first+root->val,sumRight.second+sumLeft.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        int nodeCount=0;
        dfs(root,count);
        return count;
        
        
    }
};