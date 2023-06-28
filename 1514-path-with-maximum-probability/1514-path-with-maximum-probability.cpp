class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<int>graph[n];
        vector<double>graph1[n];
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            graph1[edges[i][0]].push_back(succProb[i]);
            graph1[edges[i][1]].push_back(succProb[i]);
            
            
        }
        queue<pair<int,double>>q;
        bool flag=0;
        q.push({start,1.0});
        vector<double>vis(n,0.0);
        vis[start]=1.0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto a=q.front();
                q.pop();
                if(vis[a.first]>=a.second)
                for(int i=0;i<graph[a.first].size();i++)
                {
                    double res=graph1[a.first][i]*a.second;
                    if(res>vis[graph[a.first][i]])
                    {
                        vis[graph[a.first][i]]=res;
                        q.push({graph[a.first][i],res});
                    }
                }
            }
        }
        return vis[end];
        
    }
};