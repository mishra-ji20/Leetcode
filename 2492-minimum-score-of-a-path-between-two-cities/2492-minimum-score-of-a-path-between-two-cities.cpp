class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool>vis(n+1,0);
        vector<pair<int,int>>graph[n+1];
        for(int i=0;i<roads.size();i++)
        {
          
            graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int ans=INT_MAX;
        queue<int>q;
        q.push(1);
        vis[1]=1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
               auto a=q.front();
                q.pop();
                
                for(int i=0;i<graph[a].size();i++)
                {
                    ans=min(ans,graph[a][i].second);
                    if(vis[graph[a][i].first]==0)
                    {
                        q.push(graph[a][i].first);
                        vis[graph[a][i].first]=1;
                    }
                }
            }
        }
       
        return ans;;
        
    }
};