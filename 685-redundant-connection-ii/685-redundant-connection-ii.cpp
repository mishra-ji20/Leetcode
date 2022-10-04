class Solution {
public:
   int func(vector<int>&graph,int i)
   {
       if(graph[i]==i)
           return graph[i];
       return func(graph,graph[i]);
   }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
       vector<int>graph(edges.size()+1,0);
        vector<int>cana;
        vector<int>canb;
        for(int i=0;i<edges.size();i++)
        {
            if(graph[edges[i][1]]!=0){
                canb=edges[i];
                cana={graph[edges[i][1]],edges[i][1]};
                edges[i][1]=0;
            }
            graph[edges[i][1]]=edges[i][0];
        }
        for(int i=1;i<=edges.size();i++)
        {
            graph[i]=i;
        }
        for(auto edge:edges)
        {
            if(edge[1]==0)continue;
            int u=edge[0],v=edge[1],parent=func(graph,u);
            if(parent==v)
            {
                if(cana.empty())return edge;
                return cana;
            }
            graph[edge[1]]=parent;  
        }
        return canb;
        
    }
};