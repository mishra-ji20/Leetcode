class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int [] dp=new int[arr.length+1];
        for(int i=1;i<=arr.length;i++){
            int x=arr[i-1];
            int cnt=1;
            for(int j=i;j>0 && j>i-k;j--){
                x=Math.max(arr[j-1],x);
                dp[i]=Math.max(dp[i],(x*cnt)+dp[j-1]);
                cnt++;
            }
            // System.out.print(dp[i]+" ");
        }
        return dp[arr.length];
        
        
    }
}