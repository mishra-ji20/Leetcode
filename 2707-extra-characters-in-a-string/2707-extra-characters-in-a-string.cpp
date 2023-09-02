class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp;
        for(int i=0;i<dictionary.size();i++)
        {
            mp[dictionary[i]]=1;
        }
        vector<int>dp(s.size()+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=s.size();i++)
        {
            string temp;
            int counter=dp[i];
            // cout<<dp[i]<<" ";
            for(int j=i+1;j<=s.size();j++)
            {
                temp.push_back(s[j-1]);
                counter++;
                if(mp[temp])
                {
                    dp[j]=min(dp[j],dp[i]);
                }
                else
                    dp[j]=min(dp[j],counter);
            }
        }
        return dp[s.size()];
        
    }
};