class Solution {
public:
    int dp[31][1001];
    int recur(int n, int k, int target){
        int mod=1000000007;
        if((n==0 || target<=0)){
            return n==target;
        }
        if(dp[n][target]){
            return dp[n][target]-1;
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            ans=((ans%mod)+(recur(n-1,k,target-i)))%mod;
            
        }
        dp[n][target]=(ans%mod)+1;
        return (ans%mod);
    }
    
    int numRollsToTarget(int n, int k, int target) {
    
        dp[0][0]=1;
        return recur(n,k,target);
        
    }
};