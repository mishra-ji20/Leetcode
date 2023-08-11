class Solution {
    public int change(int amount, int[] coins) {
        // System.out.println(coins.length);
        int [][]dp=new int[coins.length+1][amount+1];
        dp[0][0]=1;
        for(int i=1;i<=coins.length;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                dp[i][j]=dp[i][j]+dp[i-1][j]+(j-coins[i-1]>=0?dp[i][j-coins[i-1]]:0);
                // System.out.print(dp[i][j]+" ");
            }
            // System.out.println();
        }
        return dp[coins.length][amount];
    }
}