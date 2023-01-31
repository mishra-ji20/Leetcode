class Solution {
public:
    static bool comp(vector<int> &a ,vector<int> &b)
    {
        if(a[0]!=b[0])
        return a[0]<b[0];
        return a[1]<b[1];
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>arr;
        for(int i=0;i<scores.size();i++)
        {
            vector<int>temp{ages[i],scores[i]};
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end(),comp);
        long long ans=arr[0][1];
        vector<long long>dp(scores.size(),0);
        dp[0]=(long)arr[0][1];
        for(int i=1;i<scores.size();i++)
        {
            long long ma=0;
            for(int j=0;j<i;j++)
            {
                if(arr[i][1]>=arr[j][1])
               ma=ma>=dp[j]?ma:dp[j];
            }
           dp[i]=(long)arr[i][1]+ma;
            ans=ans>dp[i]?ans:dp[i];
        }
        return ans;
    }
};