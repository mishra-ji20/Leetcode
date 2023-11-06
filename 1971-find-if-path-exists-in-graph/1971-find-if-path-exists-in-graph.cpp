class Solution {
public:
    bool dfs(vector<int>graph[],vector<int>&vis,int curr,int target) {
        // cout<<curr<<" ";
        if(curr==target){
            return true;
        }
        vis[curr]=1;
        bool a=0;
        for(int i=0;i<graph[curr].size();i++) {
            if(vis[graph[curr][i]]!=1)
            a=a|dfs(graph,vis,graph[curr][i],target);
        }
        return a;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int>vis(n,0);
        vector<int>graph[n];
        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(graph,vis,source,destination);
    }
};