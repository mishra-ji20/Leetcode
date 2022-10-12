class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            dp.push_back((long)dp[i-1]+(long)nums[i]);
           
        }
        int ans=INT_MAX;
        int mid;
        for(int i=0;i<dp.size()-1;i++)
        {
            int a=(dp[i]/(i+1));
            int b=(dp[nums.size()-1]-dp[i])/(nums.size()-1-i);
            if(ans>abs(a-b))
            {
                ans=abs(a-b);
                mid=i;
            }
        }
        if(ans>dp[nums.size()-1]/nums.size())
        {
            mid=nums.size()-1;
        }
                    return mid;
    }
};