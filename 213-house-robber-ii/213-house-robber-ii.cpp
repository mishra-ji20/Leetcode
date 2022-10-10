class Solution {
public:
    int rob(vector<int>& nums) {
        int ans=INT_MIN;
        if(nums.size()<=3)
        {
            for(int i=0;i<nums.size();i++)
                ans=max(ans,nums[i]);
            return ans;
                
        }
        
        vector<int>dp(nums.size()-1,0);
         vector<int>dp1(nums.size()-1,0);
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp1[1]=nums[2];
        dp1[0]=nums[1];
        for(int i=2;i<dp.size();i++)
        {
            dp[i]=max(max(dp[i-1],dp[i-2]+nums[i]),dp[i-1]-nums[i-1]+nums[i]);
        }
        for(int i=2;i<dp.size();i++)
        {
            dp1[i]=max(max(dp1[i-1],dp1[i-2]+nums[i+1]),dp1[i-1]-nums[i]+nums[i+1]);
        }
        return max(dp[dp.size()-1],dp1[dp.size()-1]);
           
    }
};