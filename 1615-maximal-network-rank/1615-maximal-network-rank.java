class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        ArrayList<HashSet<Integer>>graph=new ArrayList<HashSet<Integer>>();
        for(int i=0;i<n;i++)
        {
            graph.add(new HashSet<Integer>());
        }
        for(int i=0;i<roads.length;i++)
        {
            graph.get(roads[i][0]).add(roads[i][1]);
            graph.get(roads[i][1]).add(roads[i][0]);
        }
        int ma=0;
        for(int i=0;i<graph.size();i++)
        {
            for(int j=i+1;j<graph.size();j++)
            {
                int flag=0;
                if(graph.get(i).contains(j))
                    flag=1;
                ma=Math.max(ma,graph.get(i).size()+graph.get(j).size()-flag);
            }
        }
        return ma;
        
    }
}