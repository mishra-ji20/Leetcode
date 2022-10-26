class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
             int ma=0;
            for(int j=1,k=i-1;j<=k;j++,k--)
            {
                int a=max(dp[j],j);
                int b=max(dp[k],k);
              int ans=a*b;
               ma=ans>ma?ans:ma; 
               
            }
            dp[i]=ma;
        }
        return dp[n];
        
    }
};