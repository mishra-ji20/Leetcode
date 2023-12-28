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
    bool isEvenOddTree(TreeNode* root) {
        int level=0;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            int ma=0;
            int mi=INT_MAX;
            while(s--){
                TreeNode* head=q.front();
                if(head->left)q.push(head->left);
                if(head->right)q.push(head->right);
                if(level&1){
                    if(head->val&1){
                        return false;
                    }
                    if(head->val<=mi-1){
                        mi=head->val;
                    }else {
                        return false;
                    }
                }else{
                    // cout<<head->val<<' ';
                    if((head->val&1)==0){
                        return false;
                    }
                    if(head->val>=ma+1){
                        ma=head->val;
                    }else {
                        return false;
                    }
                    
                }
                q.pop();
            }
            cout<<endl;
            level++;
            
        }
        return true;
        
        
    }
};