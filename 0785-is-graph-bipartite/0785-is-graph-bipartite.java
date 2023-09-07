class Solution {
    public boolean isBipartite(int[][] graph) {
        Queue<Integer> q=new LinkedList();
        q.add(0);
        int [] vis=new int[graph.length];
        int flag=0;
        for(int x=0; x<graph.length;x++){
            if(vis[x]==0){
                vis[x]=1;
                q.add(x);
                flag=2;
            }
            while(q.size()>0) {
                int s=q.size();
                while(s-- > 0) {
                    Integer a=q.remove();
                    // System.out.print(a +" ");
                    for(int i=0;i<graph[a].length;i++) {
                        if(vis[graph[a][i]]!=0) {
                            if(vis[graph[a][i]]!=flag)
                                return false;
                        }else {
                            vis[graph[a][i]]=flag;
                            q.add(graph[a][i]);
                        }

                    }

                }
                if(flag==1) {
                    flag=2;
                }
                else
                    flag=1;
            }
        }
        return true;
        
    }
}