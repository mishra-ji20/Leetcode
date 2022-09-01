class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j,int &flag)
    {
        if(i>=grid.size() ||j>=grid[0].size() ||i<0 || j<0 ||grid[i][j] ||vis[i][j])
            return ;
        vis[i][j]=1;
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)
            flag=1;
        dfs(grid,vis,i+1,j,flag);
         dfs(grid,vis,i-1,j,flag);
         dfs(grid,vis,i,j+1,flag);
         dfs(grid,vis,i,j-1,flag);
    }
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(vis[i][j]==0 && grid[i][j]==0)
                {
                    int flag=0;
                    dfs(grid,vis,i,j,flag);
                    if(flag==0)
                        count++;   
                }
            }
            
        }
        return count;
    
        
    }
};