class Solution {
public:
    int recur(int i,vector<int>&manager,vector<int>&it,vector<int>&dp)
    {
        if(dp[i]!=-1)
        {
            return it[i]+dp[i];
        }
        else
            return it[i]+recur(manager[i],manager,it,dp);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& it) {
      int ans=INT_MIN;
        vector<int>dp(n,-1);
        dp[headID]=0;
      for(int i=0;i<manager.size();i++)
      {
          if(manager[i]!=-1)
          dp[i]=recur(i,manager,it,dp)-it[i];
          ans=max(ans,dp[i]);
      }
        return ans;
        
    }
};