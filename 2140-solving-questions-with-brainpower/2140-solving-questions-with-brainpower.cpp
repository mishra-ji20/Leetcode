class Solution {
public:
    long long mostPoints(vector<vector<int>>& queries) {
        vector<long long>dp(queries.size()+1,0);
        long long ans=0;
        for(int i=1;i<=queries.size();i++)
        {
            if(i<queries.size())
            {
                dp[i+1]=max(dp[i],dp[i+1]);
            }
            dp[i]=dp[i]>queries[i-1][0]+dp[i]?dp[i]:queries[i-1][0]+dp[i];
            if(i+queries[i-1][1]+1<dp.size())
            {
                dp[i+queries[i-1][1]+1]=dp[i]>dp[i+queries[i-1][1]+1]?dp[i]:dp[i+queries[i-1][1]+1];
            }
            ans=ans>dp[i]?ans:dp[i];
            
        }
        return ans;
        
    }
};