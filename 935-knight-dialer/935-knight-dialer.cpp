class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>>dp(n+1,vector<int>(10,0));
        for(int i=0;i<10;i++)
        {
            dp[1][i]=1;
        }
        long mod=1000000007;
        vector<vector<int>>arr
        {
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {0,3,9},
            {1,2},
            {0,1,7},
            {2,6},
            {1,3},
            {2,4}
        };
        for(int i=1;i<=n-1;i++)
        {
            for(int j=0;j<=9;j++)
            {
                if(j!=5)
               for(int k=0;k<arr[j].size();k++){
                dp[i+1][arr[j][k]]=((dp[i+1][arr[j][k]])%mod+dp[i][j]%mod)%mod;
                }
            }
        }
        int sum=0;
        for(int i=0;i<=9;i++)
        {
            // cout<<dp[n][i]<<" ";
           sum=((sum%mod)+(dp[n][i]%mod))%mod; 
        }
        return sum;
        
    }
};