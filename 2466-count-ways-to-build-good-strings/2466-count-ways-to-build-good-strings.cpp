class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,0);
        dp[0]=1;
        int mod=1000000007;
        for(int i=0;i<=high;i++)
        {
            if(i+one<=high)
            {
                dp[i+one]=((dp[i+one])%mod+(dp[i]%mod))%mod;
            }
            if(i+zero<=high)
            {
                dp[i+zero]=((dp[i+zero])%mod+(dp[i]%mod))%mod;
            }
        }
        int sum=0;
        for(int i=low;i<=high;i++)
        {
            sum=((sum%mod)+(dp[i]%mod))%mod;
        }
        return sum;
        
    }
};