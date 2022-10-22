class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
        int ans[m][n];
        ans[0][0]=grid[0][0];
        for(int i =0;i<grid.size();i++)
        {
            int sum=INT_MAX;
            
            for(int j=0;j<grid[i].size();j++)
            {
                sum=INT_MAX;
                if(i==0 && j==0)
                    continue;
                if(i-1>=0)
                    sum=min(sum,ans[i-1][j]);
                if(j-1>=0)
                    sum=min(sum,ans[i][j-1]);
                
                ans[i][j]=sum+grid[i][j]; 
            }
        }
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[i].size();j++)
        // cout<<ans[i][j]<<" ";
        //     cout<<endl;
        // }
        
        return ans[grid.size()-1][grid[0].size()-1];
        
        
    }
};