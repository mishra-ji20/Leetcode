class Solution {
public:
    double knightProbability(int n, int limit, int row, int column) {
        vector<vector<int>>dir={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
        vector<vector<vector<double>>>dp(limit+1,vector<vector<double>>(n,vector<double>(n,0)));
        double sum=0.0;
        dp[0][row][column]=1;
        for(int i=0;i<=limit;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    // cout<<dp[i][j][k]<<" ";
                   if(dp[i][j][k]!=0)
                   {
                       if(i==limit)
                           {
                               // cout<<(dp[i][j][k]/pow(8,limit))<<" ";
                              sum+=(dp[i][j][k]); 
                           }
                       else
                       for(int cnt=0;cnt<dir.size();cnt++)
                       {
                          
                           
                           int rc=j+dir[cnt][0];
                           int cc=k+dir[cnt][1];
                           if(rc>=0 && cc>=0 && rc<n && cc<n)
                           {
                               dp[i+1][rc][cc]+=(dp[i][j][k])/8;
                           }
                           
                       }
                   }
                }
                // cout<<endl;
            }
            // cout<<endl;
        }
        return sum;
        
        

    }
};