class Solution {
public:
    void dfs(int node,int curr,vector<int>graph[],vector<int>&vis,vector<vector<int>>&ans){
        vis[curr]=1;
        if(node!=curr)
        ans[curr].push_back(node);
        for(int i=0;i<graph[curr].size();i++){
            if(vis[graph[curr][i]]==0){
                dfs(node,graph[curr][i],graph,vis,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>graph[n];
        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,i,graph,vis,ans);
        }
        return ans;
        
    }
};