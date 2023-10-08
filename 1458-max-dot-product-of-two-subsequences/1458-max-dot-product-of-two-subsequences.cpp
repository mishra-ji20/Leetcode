class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<long>>dp(nums1.size()+1,vector<long>(nums2.size()+1,LONG_MIN));
        for(int i=0;i<=nums1.size();i++) {
            for(int j=0;j<=nums2.size();j++) {
                if(i==0 || j==0) {
                    dp[i][j]=0;
                } else {
                    dp[i][j]=nums1[i-1]*nums2[j-1]+(dp[i-1][j-1]>0?dp[i-1][j-1]:0)>dp[i][j]?nums1[i-1]*nums2[j-1]+(dp[i-1][j-1]>0?dp[i-1][j-1]:0):dp[i][j];
                }
                if(i>1){
                    dp[i][j]=dp[i-1][j]>dp[i][j]?dp[i-1][j]:dp[i][j];
                }
                if(j>1){
                    dp[i][j]=dp[i][j-1]>dp[i][j]?dp[i][j-1]:dp[i][j];
                }
                // cout<<dp[i][j]<<" ";
                
            }
            // cout<<endl;
        }
        return dp[nums1.size()][nums2.size()]; 
    }
};