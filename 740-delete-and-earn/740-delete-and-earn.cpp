class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int,int>>arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();)
        {
            int j=i;
            
            while(j<nums.size() &&nums[i]==nums[j])
            {
                j++;
            }
            arr.push_back({nums[i],nums[i]*(j-i)});
            i=j;
        }
        vector<int>dp(arr.size(),0);
        if(dp.size()<2)
            return arr[0].second;
        dp[0]=arr[0].second;
        dp[1]=(arr[1].first-arr[0].first==1)?max(arr[1].second,dp[0]):dp[0]+arr[1].second;
        for(int i=2;i<arr.size();i++)
        {
            if(arr[i].first-arr[i-1].first==1)
                dp[i]=max(arr[i].second+dp[i-2],dp[i-1]);
            else
                dp[i]=arr[i].second+dp[i-1];
        }
        return dp[arr.size()-1];
        
    }
};