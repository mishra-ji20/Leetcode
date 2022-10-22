class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
            for(int i=0;i<matrix[0].size();i++)
            {
                dp[0][i]=matrix[0][i];
            }
            for(int i=1;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    if(j>0)
                        dp[i][j]=min(dp[i-1][j-1]+matrix[i][j],dp[i][j]);
                     if(j<matrix[0].size()-1)
                        dp[i][j]=min(dp[i-1][j+1]+matrix[i][j],dp[i][j]);
                     dp[i][j]=min(dp[i-1][j]+matrix[i][j],dp[i][j]);
                }
            }
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)
        {
            ans=min(dp[matrix.size()-1][i],ans);
        }
        return ans;
        
    }
};