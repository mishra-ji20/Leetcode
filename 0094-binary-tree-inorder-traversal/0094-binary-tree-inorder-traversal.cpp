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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *temp=root;
        stack<TreeNode*>st;
        vector<int>ans;
        while(temp!=NULL || (!st.empty())){
            while(temp){
                // cout<<temp->val<<" ";
                st.push(temp);
                temp=temp->left;
            }
            if(!st.empty()){
                ans.push_back(st.top()->val);
                temp=st.top()->right;
                st.pop();
            }
        }
        return ans;

        
    }
};