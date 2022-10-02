class Solution {
public:
   
    
    int numRollsToTarget(int n, int k, int target) {
        int mod=1000000007;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int l=1;l<=k;l++)
                {
                    if(j-l>=0)
                    dp[i][j]=(dp[i][j]%mod+dp[i-1][j-l]%mod)%mod;
                }
            }
        }
        return dp[n][target];
        
       
        
        
    }
};