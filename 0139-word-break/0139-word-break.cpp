class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>mp;
        for(int i=0;i<wordDict.size();i++)
        {
            mp[wordDict[i]]=1;
        }
        vector<bool>dp(s.size()+1,0);
         dp[0]=1;
        for(int i=1;i<=s.size();i++){
            if(dp[i-1]==0)
                continue;
            
            string ans;
            for(int j=i;j<=s.size();j++)
            {
                ans.push_back(s[j-1]);
                if(mp[ans]==1)
                    dp[j]=1;
            }   
        }
        return dp[s.size()];
            
        
    }
};