class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<long long>>bucket(words[0].size(),vector<long long>(26,0));
        long long mod=1000000007;
        for(int i=0;i<words[0].size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                bucket[i][words[j][i]-'a']++;
            }
        }
        // for(int i=0;i<words[0].size();i++)
        // {
        //     for(int j=0;j<26;j++)
        //     {
        //         cout<<bucket[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<long long>>dp(target.size(),vector<long long>(words[0].size()+1,0));
        for(int i=1;i<=words[0].size();i++)
        {
            dp[0][i]=((dp[0][i-1])%mod+(bucket[i-1][target[0]-'a'])%mod)%mod;
            // cout<<dp[0][i]<<" ";
        }
        // cout<<endl;
        for(int i=1;i<target.size();i++)
        {
            for(int j=1;j<=words[0].size();j++)
            {
                dp[i][j]=((dp[i][j-1])%mod+(((dp[i-1][j-1])%mod)*((bucket[j-1][target[i]-'a'])%mod))%mod)%mod;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
            
        }
        return dp[target.size()-1][words[0].size()]%mod;
    }
};