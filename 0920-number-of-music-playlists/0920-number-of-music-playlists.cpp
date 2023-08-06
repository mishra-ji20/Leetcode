class Solution {
public:
    int min( int a,int b)
    {
        if(a<b)
            return a;
        return b;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>>dp(goal+1,vector<long>(n+1,0));
        int mod=1000000007;
        dp[0][0]=1;
        for(int i=1;i<=goal;i++)
        {
            for(int j=1;j<=min(n,i);j++)
            {
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) %mod;
                if(j>k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % mod;
               
                            // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[goal][n];
        
    }
};