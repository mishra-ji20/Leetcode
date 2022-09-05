/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int a=q.size();
            vector<int>ans;
            while(a--)
            {
                Node* temp=q.front();
                for(int i=0;i<temp->children.size();i++)
                {
                    if(temp->children[i])q.push(temp->children[i]);
                }
                ans.push_back(temp->val);
                q.pop();
            }
            res.push_back(ans);
        }
        return res;
        
    }
};