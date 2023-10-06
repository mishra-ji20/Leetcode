class Solution {
public:
    int sol(vector<int> &dp,int n) {
         if(n==0)
            return 1;
         if(dp[n]>0)
            return dp[n];
        for(int i=1;i<=n;i++) {
                dp[n]=max(dp[n],i*sol(dp,n-i));
        }
        return dp[n];
        
    }
    int integerBreak(int n) {
        
       
        if(n==2 || n==3)
            return n-1;
        vector<int>dp(n+1,0);
        return sol(dp,n);
       
    }
};