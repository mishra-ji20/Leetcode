class Solution {
    public int uniquePathsWithObstacles(int[][] obstacles) {
        int [][]dp=new int[obstacles.length][obstacles[0].length];
        if(obstacles[0][0]==1)
            return 0;
        dp[0][0]=1;
        for(int i=0;i<obstacles.length;i++)
        {
            for(int j=0;j<obstacles[0].length;j++){
            if(obstacles[i][j]!=1)
            dp[i][j]+=(i>0?dp[i-1][j]:0)+(j>0?dp[i][j-1]:0);
            }
        }
        return dp[obstacles.length-1][obstacles[0].length-1];
            
        
    }
}