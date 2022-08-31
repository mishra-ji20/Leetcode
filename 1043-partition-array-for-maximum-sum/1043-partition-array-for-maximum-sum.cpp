class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,0);
        for(int i=1;i<=arr.size();i++)
        {
           int j=i;
            int a=k;
            int ma=arr[i-1];
            while(j>0 && a--)
            {
                ma=max(ma,arr[j-1]);
                dp[i]=max(dp[i],(i-j+1)*ma+dp[j-1]);
                j--;
            } 
        }
       
        return dp[arr.size()];
        
    }
};