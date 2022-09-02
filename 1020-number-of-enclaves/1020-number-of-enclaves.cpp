class Solution {
public:
     void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j,int &flag,int &sum)
    {
        if(i>=grid.size() ||j>=grid[0].size() ||i<0 || j<0 ||grid[i][j]==0 ||vis[i][j])
            return ;
        vis[i][j]=1;
         sum++;
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)
            flag=1;
        dfs(grid,vis,i+1,j,flag,sum);
         dfs(grid,vis,i-1,j,flag,sum);
         dfs(grid,vis,i,j+1,flag,sum);
         dfs(grid,vis,i,j-1,flag,sum);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    int flag=0,sum=0;
                    dfs(grid,vis,i,j,flag,sum);
                    if(flag==0)
                        count=count+sum;   
                }
            }
            
        }
        return count;
    
        
        
    }
};