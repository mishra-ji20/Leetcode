class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_map<int,int>mp;
        vector<int>dp;
        dp.push_back(1);
        if(n==1)
            return 1;
        int i=0,j=0,k=0;
        int count=1;
        while(count<n)
        {
            int mi=min(2*dp[i],min(3*dp[j],5*dp[k]));
           if(mi==2*dp[i])
               i++;
           if(mi==3*dp[j])
               j++;
             if(mi==5*dp[k])
               k++;
            if(mi==1)
            {
                continue;
            }
            else
            {
                dp.push_back(mi);
                mp[mi]=1;
                count++;
            }
        }
        return dp[n-1];
        
    }
};