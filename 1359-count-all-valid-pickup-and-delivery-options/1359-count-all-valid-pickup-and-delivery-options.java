class Solution {
    public int countOrders(int n) {
        long [] dp=new  long [n+1];
        long mod=1000000007;
        dp[1]=1;
        for(int i=2;i<=n;i++) {
            int a=2*i-1;
            dp[i]=((dp[i-1]%mod)*(((a*(a+1))/2)%mod))%mod;
        }
        return (int)dp[n];
        
    }
}