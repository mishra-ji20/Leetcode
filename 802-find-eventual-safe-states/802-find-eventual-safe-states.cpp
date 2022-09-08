class Solution {
public:
    int dfs(vector<vector<int>>&graph,int i,vector<int>&vis,vector<int>&dp)
    {
        if(vis[i])
            return dp[i];
        vis[i]=1;
        int a=1;
        for(int j=0;j<graph[i].size();j++)
        {
             a=(a&(dfs(graph,graph[i][j],vis,dp)));
        }
        dp[i]=a;
        return dp[i];
                   
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>dp(graph.size(),0);
        vector<int>vis(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(graph[i].size()==0)
                dp[i]=1;
        }
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==0)
            {
                dfs(graph,i,vis,dp);
            }

        }
        vector<int>ans;
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i])
                ans.push_back(i);
                
        }
        return ans;
        
        
        
    }
};