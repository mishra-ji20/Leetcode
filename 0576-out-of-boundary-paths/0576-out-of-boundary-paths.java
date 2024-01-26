class Solution {
    int [][]dir={{1,0},{0,1},{-1,0},{0,-1}};
    int [][][] dp=new int[51][51][51];
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        int mod=1000000007;
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n){
            return 1;
        }
        if(dp[startRow][startColumn][maxMove]!=0){
            return dp[startRow][startColumn][maxMove]+1;
        }
        int ans=0;
        for(int i=0;i<dir.length;i++){
            if(maxMove>0){
                ans=((ans%mod)+((findPaths(m,n,maxMove-1,startRow+dir[i][0],startColumn+dir[i][1]))%mod))%mod;
                
            }
           
        }
        dp[startRow][startColumn][maxMove]=ans-1;
        return dp[startRow][startColumn][maxMove]+1;
        
        
    }
}