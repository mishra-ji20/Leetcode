class Solution {
public:
    class Node{
        public:
        vector<Node*>val;
        int eow;
        Node(){
            for(int i=0;i<26;i++)
                val.push_back(NULL);
            eow=0;
        }
    };
    void dfs(Node *root,vector<string>&sol, string &res, int &count)
    {
        if(count>=3)
            return ;
        if(root->eow==1)
        {
            sol.push_back(res);
            count++;
        }
        for(int i=0;i<26;i++)
        {
            if(root->val[i])
            {
                // cout<<char('a'+i);
                res.push_back('a'+i);
                dfs(root->val[i],sol,res,count);
                res.pop_back();
            }
        }
            
    }
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        Node* root=new Node();
        Node *temp=root;
        for(int i=0;i<p.size();i++)
        {
            root=temp;
            for(int j=0;j<p[i].size();j++)
            {
                if(root->val[p[i][j]-'a']==NULL)
                root->val[p[i][j]-'a']=new Node();
                root=root->val[p[i][j]-'a'];
                 if(j==p[i].size()-1)
                 { 
                    root->eow=1;
                 }
            }
           
        }
        root=temp;
        vector<vector<string>>ans;
        string res;
        for(int i=0;i<s.size();i++)
        {
            res.push_back(s[i]);
            if(root)
            root=root->val[s[i]-'a'];
            vector<string>sol;
            int count=0;
            if(root)
            dfs(root,sol,res,count);
            ans.push_back(sol);
            
        }
        return ans;
          
    }
};