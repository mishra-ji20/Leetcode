class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(coins[j]>i)
                    continue;
                else{
                    int a=dp[i-coins[j]];
                    if(a!=INT_MAX)
                        a=a+1;
                
                    dp[i]=min(dp[i],a);
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        else
            return dp[amount];
        
    
        
    }
};