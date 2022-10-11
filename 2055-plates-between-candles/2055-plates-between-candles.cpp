class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>left(s.size(),0);
        vector<int>right(s.size(),0);
        vector<int>dp(s.size()+1,0);
        int near=s.size();
        int nel=-1;
        for(int i=s.size()-1,j=0;i>=0;i--,j++)
        {
            if(s[i]=='|')
            {
                near=i;
            }
            right[i]=near;  
            if(s[j]=='|')
                nel=j;
            left[j]=nel;
            if(s[j]=='|')
            {
                dp[j+1]=dp[j];
            }
            else
                dp[j+1]=dp[j]+1;
        }
        vector<int>res;
        for(int i=0;i<queries.size();i++)
        {
            int l=right[queries[i][0]];
            int r=left[queries[i][1]];
            if(l>r)
                res.push_back(0);
            else
            res.push_back(dp[r+1]-dp[l]);
        }
        return res;
    }
};