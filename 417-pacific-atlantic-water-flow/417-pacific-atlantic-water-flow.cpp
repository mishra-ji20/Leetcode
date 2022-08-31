class Solution {
public:
    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j)
    {
        
        vis[i][j]=1;
        if(i>0 && grid[i-1][j]>=grid[i][j] && vis[i-1][j]==0)
        dfs(grid,vis,i-1,j);
        if(j>0 && grid[i][j-1]>=grid[i][j] && vis[i][j-1]==0)
        dfs(grid,vis,i,j-1);
        if(j<grid[0].size()-1 && grid[i][j+1]>=grid[i][j] && vis[i][j+1]==0)
        dfs(grid,vis,i,j+1);
        if(i<grid.size()-1 && grid[i+1][j]>=grid[i][j] && vis[i+1][j]==0)
        dfs(grid,vis,i+1,j);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>>vis1(heights.size(),vector<bool>(heights[0].size(),0));
        vector<vector<bool>>vis2(heights.size(),vector<bool>(heights[0].size(),0));
        for(int i=0;i<heights[0].size();i++)
        {
            if(vis1[0][i]==0)
            {
               dfs(heights,vis1,0,i); 
            }
        }
        for(int i=0;i<heights.size();i++)
        {
            if(vis1[i][0]==0)
            {
               dfs(heights,vis1,i,0); 
            }
        }
        for(int i=0;i<heights[0].size();i++)
        {
            if(vis2[heights.size()-1][i]==0)
            {
               dfs(heights,vis2,heights.size()-1,i); 
            }
        }
        for(int i=0;i<heights.size();i++)
        {
            if(vis2[i][heights[0].size()-1]==0)
            {
               dfs(heights,vis2,i,heights[0].size()-1); 
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(vis1[i][j]&vis2[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
        
        
        
    }
};