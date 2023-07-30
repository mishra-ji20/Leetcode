class Solution {
public:
    int min(int a,int b)
    {
        if(a<b)
            return a;
        return b;
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<vector<int>>>dp(words.size(),vector<vector<int>>(26,vector<int>(26,INT_MAX)));
        int ans=INT_MAX;
        dp[0][words[0][0]-'a'][words[0][words[0].size()-1]-'a']=words[0].size();
        if(words.size()==1)
            ans=words[0].size();
        for(int i=1;i<words.size();i++)
        {
            int a=words[i][0]-'a';
            int b=words[i][words[i].size()-1]-'a';
            // cout<<a<<" "<<b<<" ";
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<26;k++)
                {
                    if(dp[i-1][j][k]!=INT_MAX)
                    {
                        int flag=0;
                        if(k==a)
                           flag=1;
                        dp[i][j][b]=min(dp[i][j][b],dp[i-1][j][k]+words[i].size()-flag);
                        flag=0;
                        if(j==b)
                            flag=1;
                        dp[i][a][k]=min(dp[i][a][k],dp[i-1][j][k]+words[i].size()-flag);
                        if(i==words.size()-1){
                            ans=min(ans,dp[i][j][b]);
                            ans=min(ans,dp[i][a][k]);
                        }
                            
                    }
                }
            }
        }
        return ans;
        
    }
};