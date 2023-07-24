class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        bool flag=1;
        if(nums[0]%2==0)
            flag=0;
        vector<long long> temp;
        for(int i=0;i<nums.size();)
        {
            int j=i;
            long long sum=0;
            while(j<nums.size() && (nums[j]&1)==flag)
            {
              sum+=nums[j]; 
                j++;
            }
            // cout<<j<<" ";
            cout<<sum<<" ";
            i=j;
            temp.push_back(sum);
            flag=(!flag);
            
        }
        vector<long long>dp(temp.size(),LLONG_MIN);
        dp[0]=temp[0];
        // cout<<temp[0]<<" ";
        long long ans=dp[0];
        // cout<<dp.size()<<" ";
        for(int i=0;i<((int)dp.size())-1;i++)
        {
            if(i<((int)dp.size())-1){
            dp[i+1]=max(dp[i+1],dp[i]+temp[i+1]-x);
            ans=max(ans,dp[i+1]);
            }
            if(i<((int)dp.size())-2){
            dp[i+2]=max(dp[i+2],dp[i]+temp[i+2]);
            ans=max(ans,dp[i+2]);
            }
            // ans=(ans>dp[i+1])?(ans>dp[i+2]?ans:dp[i+2]):(dp[i+1]>dp[i+2]?dp[i+1]:dp[i+2]);
        }
        return ans;
            
        
    }
};