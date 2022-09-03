class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        int sol=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
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
                if(grid[i][j]==0)
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
};