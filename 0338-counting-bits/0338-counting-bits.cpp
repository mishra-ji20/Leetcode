class Solution {
public:
    int power(int a)
    {
        int pro=1;
        for(int i=0;i<a;i++)
            pro=pro*2;
        return pro;
    }
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
            if(n==0)
                return dp;
        dp[1]=1;
        int a=1;
        int j=power(a);
        while(j<=n)
        {
            for(int i=0;i<j && i+j<=n;i++)
            {
                dp[i+j]=1+dp[i];
            }
            a++;
            j=power(a);
        }
        return dp;
    }
};