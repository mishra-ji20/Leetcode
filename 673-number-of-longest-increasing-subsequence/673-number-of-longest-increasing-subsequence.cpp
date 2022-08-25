class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        dp[0]=1;
        vector<int>ans(nums.size(),0);
        ans[0]=1;
        int sum=0;
        for(int i=1;i<dp.size();i++)
        {
            bool flag=0;
            int ma=0;
            sum=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[j]>ma)
                {
                    ma=dp[j];
                    sum=ans[j];     
                }
                else if(nums[j]<nums[i] && dp[j]==ma)
                {
                    sum=sum+ans[j];
                }
            }
            dp[i]=ma+1;
            if(sum==0)sum++;
            ans[i]=sum;
        }
        int m_ind=0;
        sum=ans[0];
        for(int i=1;i<dp.size();i++)
        {
            
            if(dp[i]>dp[m_ind])
            {
                m_ind=i;
                sum=ans[i];
            }
            else if(dp[i]==dp[m_ind])
            {
                sum=sum+ans[i];
            }
        }
        return sum;
    }
    
};