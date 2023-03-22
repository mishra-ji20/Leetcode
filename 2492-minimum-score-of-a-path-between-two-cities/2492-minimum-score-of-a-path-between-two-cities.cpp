class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool>vis(n+1,0);
        vector<int>graph[n+1];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<roads.size();i++)
        {
            pq.push({roads[i][2],i});
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
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
                    if(vis[graph[a][i]]==0)
                    {
                        q.push(graph[a][i]);
                        vis[graph[a][i]]=1;
                    }
                }
            }
        }
        while(!pq.empty())
        {
            auto a=pq.top();
            // cout<<a.first<<" ";
            if(vis[roads[a.second][1]] || vis[roads[a.second][0]])
                return a.first;
            pq.pop();
        }
        return -1;
        
    }
};