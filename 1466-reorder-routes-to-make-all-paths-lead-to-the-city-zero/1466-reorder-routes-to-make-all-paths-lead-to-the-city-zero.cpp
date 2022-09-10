class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>graph[n];
       unordered_map<int,unordered_map<int,int>>mp;
        int count=0;
        for(int i=0;i<connections.size();i++)
        {
            mp[connections[i][0]][connections[i][1]]=1;
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);  
            
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]=1;
        int ans=0;
        while(!q.empty())
        {
            int a=q.size();
            while(a--)
            {
                int b=q.front();
                for(int i=0;i<graph[b].size();i++)
                {
                    if(vis[graph[b][i]]==0)
                    {
                        // cout<<b<<" "<<graph[b][i]<<" ";
                        q.push(graph[b][i]);
                        vis[graph[b][i]]=1;
                        if(mp[b][graph[b][i]])
                            ans++;
                        
                    }
                }
                q.pop();
            }
        }
        return ans;
        
    }
};