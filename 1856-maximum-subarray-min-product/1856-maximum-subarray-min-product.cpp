class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod=1000000007;
        vector<long long int>dp;
        stack<int>st;
        dp.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            dp.push_back(dp[i]+(long long)nums[i]);
        }
        vector<pair<int,int>>range(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && nums[i]<=nums[st.top()])
            {
                range[st.top()].second=i;
                st.pop();
            }
            if(st.empty())
                range[i].first=0;
            else
                range[i].first=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
        {
            range[st.top()].second=nums.size();
            st.pop();
        }
        long long int ans=-1;
        for(int i=0;i<range.size();i++)
        {
            // cout<<range[i].first<<
            long long int sum=(dp[range[i].second]-dp[range[i].first])*(long long)nums[i];
            if(ans<sum)
            {
                ans=sum;
            }
        }
        return ans%mod;
    }
};