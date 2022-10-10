class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1000000007;
        vector<int>dp(arr.size()+1,0);
        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            int sum=arr[i];
            int count=0;
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            int j;
            if(st.empty())
            {
                j=-1;
            }
            else
                j=st.top();
            sum=(sum%mod+(arr[i]*(i-j-1))%mod)%mod;
            sum=(sum%mod+dp[j+1]%mod)%mod;
            st.push(i);
            dp[i+1]=sum;
            
        }
        int sum=0;
        for(int i=0;i<dp.size();i++)
        {
            // cout<<dp[i]<<" ";
            sum=(sum%mod+dp[i]%mod)%mod;
        }
        return sum;
         
    }
};