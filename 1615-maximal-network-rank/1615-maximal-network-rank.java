class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int [][] graph=new int[n][n];
        int []arr=new int[n];
        for(int i=0;i<roads.length;i++)
        {
            graph[roads[i][0]][roads[i][1]]=1;
            arr[roads[i][0]]++;
            graph[roads[i][1]][roads[i][0]]=1;
            arr[roads[i][1]]++;
            
        }
        int ma=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ma=Math.max(ma,arr[i]+arr[j]-graph[i][j]);
            }
        }
        return ma;
        
        
    }
}