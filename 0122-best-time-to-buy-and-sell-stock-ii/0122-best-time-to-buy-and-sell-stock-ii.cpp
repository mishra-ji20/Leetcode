class Solution {
public:
    int maxProfit(vector<int>& arr) {
       vector<int>dp(arr.size(),0);
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>arr[i-1])
                dp[i]=dp[i-1]+arr[i]-arr[i-1];
            else
                dp[i]=dp[i-1];
        }
        return dp[arr.size()-1];
    }
};