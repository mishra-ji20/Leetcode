class Solution {
    public int numSquares(int n) {
        int[] dp=new int [n+1];
        if(n==1){
            return 1;
        }
        int difference=3;
        ArrayList<Integer> lastPerfectSquares=new ArrayList();
        dp[1]=1;
        lastPerfectSquares.add(1);
        for(int i=2;i<=n;i++){
            if(i-lastPerfectSquares.get(lastPerfectSquares.size()-1)==difference){
                // System.out.print
                dp[i]=1;
                difference+=2;
                lastPerfectSquares.add(i);
            }else{
                dp[i]=Integer.MAX_VALUE;
                for(int j=lastPerfectSquares.size()-1;j>=0;j--){
                    dp[i]=Math.min(dp[i],1+dp[i-lastPerfectSquares.get(j)]);
                } 
            }
        }
        return dp[n];
        
    }
}