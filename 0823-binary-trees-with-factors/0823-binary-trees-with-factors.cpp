class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long mod=1e9+7;
        sort(arr.begin(),arr.end());
        vector<int>dp(arr.size(),1);
        unordered_map<int,int>mp;
        long long sum=1;
        mp[arr[0]]=1;
        for(int i=1;i<arr.size();i++) {
            long long temp=0;
            mp[arr[i]]=i+1;
            for(int j=0;j<i;j++) {
                if(arr[i]%arr[j]==0) {
                    if(mp[arr[i]/arr[j]]) {
                        // cout<<arr[i]/arr[j]<<endl;
                        temp=((temp%mod)+((dp[j]%mod)*(dp[mp[arr[i]/arr[j]]-1]%mod))%mod)%mod;
                        // cout<<(dp[j]%mod)*(dp[mp[arr[i]/arr[j]]-1];
                    }
                }
            }
            dp[i]=(dp[i]%mod)+(temp%mod)%mod;
            sum=((sum%mod)+(dp[i]%mod))%mod;
            
        }
        return sum;
       
    }
};