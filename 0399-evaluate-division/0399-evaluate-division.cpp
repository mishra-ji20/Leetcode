class Solution {
public:
    void dfs(vector<vector<double>> &graph, int src, int dest,vector<int> &vis, double ans ,double &flag){
        if(vis[src]==1)
            return;
        if(src==dest)
        {
            flag=ans;
            return;
        }
        vis[src]=1;
        for(int i=0;i<graph[src].size();i++)
        {
            if(graph[src][i]!=0 && vis[i]==0)
            {
                ans=ans*graph[src][i];
                dfs(graph,i,dest,vis,ans,flag);
                ans=ans/graph[src][i];
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int>mp;
        int cnt=1;
        for(int i=0;i<equations.size();i++)
        {
            for(int j=0;j<equations[i].size();j++)
            {
                if(mp[equations[i][j]]==0)
                {
                    mp[equations[i][j]]=cnt++;
                }
            }
        }
        vector<vector<double>>graph(cnt,vector<double>(cnt,0.0));
        for(int i=0;i<equations.size();i++)
        {
            int a=mp[equations[i][0]];
            int b=mp[equations[i][1]];
            graph[a][b]=values[i];
            graph[b][a]=((double)1/values[i]);
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++)
        {
            double flag=-1.0;
            vector<int>vis(cnt,0);
          if(mp[queries[i][0]] && mp[queries[i][1]])  {
              dfs(graph,mp[queries[i][0]],mp[queries[i][1]],vis,1.0,flag);
          }
            ans.push_back(flag);
        }
        return ans;
        
    }
};