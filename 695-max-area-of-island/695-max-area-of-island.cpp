class Solution {
public:
    void component(int i,int j,int& sum,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        vis[i][j]=1;
        sum++;
        if(i+1<grid.size() && vis[i+1][j]==0 && grid[i+1][j])
        {
            
            component(i+1,j,sum,vis,grid);
        }
        if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j])
        {
            component(i-1,j,sum,vis,grid);
        }
         if(j-1>=0 && vis[i][j-1]==0 && grid[i][j-1])
        {
            
            component(i,j-1,sum,vis,grid);
        }
         if(j+1<grid[0].size() && vis[i][j+1]==0 && grid[i][j+1])
         {
            component(i,j+1,sum,vis,grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size() ,vector<int>(grid[0].size(),0));
        int ans=0, res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(vis[i][j]==0 && grid[i][j])
                {
                    res=0;
                     component(i,j,res,vis,grid);
                    // cout<<res<<" ";
                    ans=max(ans,res);
                }
            }
        }
        return ans;
        
    }
};