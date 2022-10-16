class Solution {
public:
    int minDifficulty(vector<int>& diff, int d) {
        if(d>diff.size())
            return -1;
        vector<vector<int>>dp(d,vector<int>(diff.size(),INT_MAX));
        int ans=-1;
       vector<vector<int>>mp(diff.size(),vector<int>(diff.size(),0));
        for(int i=0;i<diff.size();i++)
        {
            int ma=-1;
            for(int j=i;j<diff.size();j++)
            {
                ma=max(diff[j],ma);
                mp[i][j]=ma;
                // cout<<mp[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int j=0;j<diff.size();j++)
        {
            ans=max(ans,diff[j]);
            dp[0][j]=ans;
        }
        for(int i=1;i<d;i++)
        {
            for(int j=i;j<diff.size();j++)
            {
                for(int k=i-1;k<j;k++)
                {
                    // cout<<dp[i-1][k]<<" "<<mp[k+1][j]<<"   ";
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+mp[k+1][j]);
                }
                // cout<<endl;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return dp[d-1][diff.size()-1];
    }
                             
        
};