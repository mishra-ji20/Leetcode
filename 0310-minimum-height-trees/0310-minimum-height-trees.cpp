class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>graph[n];
        vector<int>mp(n,0);
        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        queue<int>q;
        if(n==1)
            return {0};
        for(int i=0;i<mp.size();i++){
            if(mp[i]==1){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int s=q.size();
            res.clear();
            while(s--) {
                int x=q.front();
                res.push_back(x);
                q.pop();
                for(int i=0;i<graph[x].size();i++){
                    mp[graph[x][i]]--;
                    if(mp[graph[x][i]]==1){
                        q.push(graph[x][i]);
                    }
                }
            }
        }
        return res;
    }
        
};