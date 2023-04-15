class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i=0;i<piles.size();i++)
        {
            for(int j=1;j<piles[i].size();j++)
            {
                piles[i][j]+=piles[i][j-1];
            }
        }
        vector<vector<long long>>dp(piles.size(),vector<long long>(k+1,0));
        for(int i=1;i<=k;i++)
        {
            if(i<piles[0].size())
                dp[0][i]=piles[0][i-1];
            else
                dp[0][i]=piles[0][piles[0].size()-1];
            // cout<<dp[0][i]<<" ";
        }
        // cout<<endl;
        for(int i=1;i<piles.size();i++)
        {
            for(int j=1;j<=k;j++)
            {
                long long sum=0;
                for(int cnt1=0;cnt1<=min(j,(int)piles[i].size());cnt1++)
                {
                    
                    long long a=(cnt1-1<0)?0:cnt1-1<piles[i].size()?piles[i][cnt1-1]:piles[i][piles[i].size()-1];
                    sum=max(sum,dp[i-1][j-cnt1]+a);
                }
                // cout<<sum<<" ";
                dp[i][j]=sum;
            }
            // cout<<endl;
        }
        return dp[piles.size()-1][k];
    }
};