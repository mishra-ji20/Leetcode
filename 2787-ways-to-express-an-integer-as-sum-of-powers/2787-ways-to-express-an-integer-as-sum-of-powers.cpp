class Solution {
public:
        int Pow(int x, long n) {
        if(n==0)
            return 1;
        if(n<0)
        {
            n=(-n);
            x=1/x;
        }
        int ans=1;
        while(n>0)
        {
            if(n&1) ans=ans*x;
            x=x*x;
            n=n>>1;
            
        }
        return ans;    
    }
    int numberOfWays(int n, int x) {
        int mod=1000000007;
        vector<int>arr;
        arr.push_back(0);
        for(int i=1;pow(i,x)<=n;i++)
        {
            arr.push_back(pow(i,x));
        }
        vector<vector<int>>dp(n+1,vector<int>(arr.size(),0));
        for(int i=0;i<arr.size();i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<arr.size();j++)
            {
                int temp=0;
                if(i>=arr[j])
                    temp=(((dp[i-arr[j]][j-1])%mod))%mod;
                dp[i][j]=(dp[i][j-1]+temp)%mod;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n][arr.size()-1]%mod;
        
        
    }
};