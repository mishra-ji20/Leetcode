class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto &it: wordDict)
        {
            mp[it]=1;
        }
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<dp.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]){
                string a=s.substr(j,i-j);
                if(mp[a]){
                   dp[i]=1;
                    break;
                }
                }
            }
        }
        return dp[s.size()];
    }
};