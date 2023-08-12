class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int buckets) {
        long[][] dp=new long[piles.size()+1][buckets+1];
          int i=1;
        for(List<Integer> arr:piles){
          
            for(int j=1;j<=buckets;j++)
            {
                int k=1;
                long sum=0;
                for(Integer it:arr){
                    sum=sum+it;
                    if(j>=k){
                        dp[i][j]=Math.max(dp[i][j],sum+dp[i-1][j-k]);
                    }
                    k++;
                }
                dp[i][j]=Math.max(dp[i][j],dp[i-1][j]);
                // System.out.print(dp[i][j]+" "+ i+" "+j+"    ");
            }
            // System.out.println();
            i++;
        }
        return (int)dp[piles.size()][buckets];
    }
}