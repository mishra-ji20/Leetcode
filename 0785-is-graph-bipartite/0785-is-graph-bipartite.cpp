class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        vector<int>vis(graph.size(),0);
       int color;
        for(int i=0;i<graph.size();i++){
            if(vis[i]==0){
                q.push(i);
                vis[i]=1;
                color=1;
            }
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            color=vis[a];
            for(int i=0;i<graph[a].size();i++)
            {
                if(vis[graph[a][i]]==color)
                    return false;
                else if(vis[graph[a][i]]==0){
                    vis[graph[a][i]]=-color;
                    q.push(graph[a][i]);
                }
                
            }
            
        }
        }
        return true;
    
    }
};