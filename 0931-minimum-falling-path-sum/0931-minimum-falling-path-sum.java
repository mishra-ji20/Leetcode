class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int [][]dp=new int [matrix.length][matrix[0].length];
        int ans=Integer.MAX_VALUE;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                }else{
                    int left=j>0?dp[i-1][j-1]:Integer.MAX_VALUE;
                    int right=j<matrix[0].length-1?dp[i-1][j+1]:Integer.MAX_VALUE;
                    int up=dp[i-1][j];
                    dp[i][j]=matrix[i][j]+Math.min(Math.min(left,right),up);

                }
                if(i==matrix.length-1){
                        ans=Math.min(ans,dp[i][j]);
                }
                // System.out.print(dp[i][j]+" ");
            }
            // System.out.println();
        }
        return ans;
        
    }
}