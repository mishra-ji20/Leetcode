class Solution {
public:
    vector<vector<int>>func(vector<vector<int>>grid)
    {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        int sol=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    dp[i][j]=0;
                   
                }
                else {
                int a=INT_MAX,b=INT_MAX;
                if(i>0)a=min(a,dp[i-1][j]);
                if(j>0)b=min(b,dp[i][j-1]);
                int res=min(a,b);
                if(res!=INT_MAX)
                    dp[i][j]=res+1;
                if(res==INT_MAX)
                dp[i][j]=INT_MAX;
                }
                // cout<<dp[i][j]<<" ";
                 
            }
            // cout<<endl;
        }
        // cout<<endl;
        for(int i=grid.size()-1;i>=0;i--)
        {
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                if(grid[i][j])
                {
                    dp[i][j]=0;
                }
                else{
                int a=INT_MAX,b=INT_MAX;
                if(i<grid.size()-1)a=min(a,dp[i+1][j]);
                if(j<grid[0].size()-1)b=min(b,dp[i][j+1]);
                int res=min(a,b);
                if(res!=INT_MAX){
                    dp[i][j]=min(dp[i][j],res+1);
                }
                if(res==INT_MAX)
                dp[i][j]=min(dp[i][j],INT_MAX);
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp;
        
    }
     void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j)
    {
        if(i>=grid.size() ||j>=grid[0].size() ||i<0 || j<0 ||grid[i][j]==0||vis[i][j])
            return ;
        vis[i][j]=1;
        dfs(grid,vis,i+1,j);
         dfs(grid,vis,i-1,j);
         dfs(grid,vis,i,j+1);
         dfs(grid,vis,i,j-1);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid.size(),0));
        int flag=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
               if(grid[i][j])
               {
                   dfs(grid,vis,i,j);
                   flag=1;
                   break;
               }
            }
            if(flag)
                break;
        }
        int sol=INT_MAX;
        vector<vector<int>>dp(vis.size(),vector<int>(vis[0].size(),0));
        dp=func(vis);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] && vis[i][j]==0)
                {
                    sol=min(sol,dp[i][j]);
                }
            }
        }
        return sol-1;
       
        
        
    }
};