class Solution {
    int bfs(List<Integer>[] graph){
        int []visitedNodes = new int [graph.length];
        int target = graph.length-1;
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(0);
        int ans = 1;
        while(!q.isEmpty()){
            int size = q.size();
            while(size-- > 0){
                int topElement= q.poll();
                for(int i=0 ;i<graph[topElement].size();i++){
                    if(graph[topElement].get(i) == target ){
                        return ans;
                    }
                   if( visitedNodes[graph[topElement].get(i)] == 0 ){
                      q.add(graph[topElement].get(i));
                       visitedNodes[graph[topElement].get(i)] = 1;
                   }
                }
                
            }
            ans++;
        }
        return 0;
    }
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<Integer>[] graph = new ArrayList[n];
        for(int i=0;i<n-1;i++){
            if(graph[i]==null){
                graph[i]=new ArrayList<Integer>(List.of(i+1));
            }else{
                graph[i].add(i+1);
            }
                        
        }
        int [] ans= new int [queries.length];
        for(int i=0 ;i<queries.length;i++){
            graph[queries[i][0]].add(queries[i][1]);
            ans[i]=bfs(graph);
        }
        return ans;
        
    }
}