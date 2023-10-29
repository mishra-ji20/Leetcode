class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>>graph={{1},{0,2},{0,1,3,4},{2,4},{0}};
        int mod=1e9+7;
        vector<int>dp(5,1);
        n--;
        int sum=5;
        while(n--){
            sum=0;
            vector<int>copyDp(5,0);
            for(int i=0;i<5;i++) {
                for(int j=0;j<graph[i].size();j++) {
                    copyDp[graph[i][j]]=((copyDp[graph[i][j]]%mod)+(dp[i]%mod))%mod;
                    sum=((sum%mod)+(dp[i]%mod))%mod;
                }
                // cout<<sum<<" ";
            }
            dp=copyDp;
        }
        return sum;
        
    }
};