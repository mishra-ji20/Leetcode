class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<unsigned long long >>dp(target+1,vector<unsigned long long>(nums.size()+1,0));
        dp[0][0]=1;
        for(int i=0;i<=target;i++) {
        
            for(int j=1;j<=nums.size();j++) {
                dp[i][j]=dp[i][j-1]+(i-nums[j-1]>=0?dp[i-nums[j-1]][nums.size()]:0);
                // cout<<dp[i][j]<<" ";
            
            }
            // cout<<endl;
        }
        return dp[target][nums.size()];
    }
};