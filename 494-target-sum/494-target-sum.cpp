class Solution {
public:
    int findTargetSumWays(vector<int>&nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum=sum+nums[i];
        if((sum+abs(target))&1)return 0;
        else
            sum=(sum+abs(target))/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=nums.size();i++)
        {
        
            for(int j=0;j<=sum;j++)
            {
                if(j>=nums[i-1])
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else
                    dp[i][j]=dp[i-1][j];
                // cout<<dp[i][j]<<" ";
                
            }
            // cout<<endl;
        }
        return dp[nums.size()][sum];
        
    }
};