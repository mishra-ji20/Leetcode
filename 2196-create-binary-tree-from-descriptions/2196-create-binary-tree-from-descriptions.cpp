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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,TreeNode*>mp;
        unordered_map<int,int>mpParent;
        for(int i=0;i<des.size();i++){
            
            if(mp[des[i][0]]==NULL){
                mp[des[i][0]]=new TreeNode(des[i][0]);
            }
            if(mp[des[i][1]]==NULL){
                mp[des[i][1]]=new TreeNode(des[i][1]);
            }
            if(des[i][2]==1){
               mp[des[i][0]]->left=mp[des[i][1]];
            }else{
                mp[des[i][0]]->right=mp[des[i][1]]; 
            }
            // cout<<des[i][1]<<" "<<des[i][0]<<"            ";
            mpParent[des[i][1]]=des[i][0];
        }
        int x=des[0][0];
        // cout<<x<<" ";
        // cout<<mpParent[x]<<' ';
        while(mpParent[x]){
            // cout<<x<<" ";
            x=mpParent[x];
        }
        return mp[x];
        
    }
};