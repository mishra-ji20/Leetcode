class Solution {
public:
    bool check(vector<vector<int>> &graph,vector<int>vis){
        int cnt=0;
        for(int i=0;i<vis.size();i++){
            if(vis[i]){
                cnt++;
                for(int j=0;j<graph[i].size();j++){
                    if(graph[i][j]){
                        // cout<<j<<" ";
                        vis[j]++;
                    }
                }
                // cout<<endl<<i<<endl;
            }
        }
        // cout<<endl;
        for(int i=0;i<vis.size();i++){
            // cout<<vis[i]<<' ';
            if(vis[i]!=0 && vis[i]!=cnt){
                // cout<<endl;
                return false;
            }
        }
        // cout<<endl;
        return true;
    }
    void dfs(int curr,vector<vector<int>> &graph,vector<int>&vis,vector<int> &visTemp){
        vis[curr]=1;
        visTemp[curr]=1;
        for(int i=0;i<graph[curr].size();i++){
            if(graph[curr][i] && vis[i]==0){
                dfs(i,graph,vis,visTemp);
            }
        }
    } 
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n,vector<int>(n,0));
        for(int i=0;i<edges.size();i++){
            graph[edges[i][1]][edges[i][0]]=1;
            graph[edges[i][0]][edges[i][1]]=1;
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vector<int>tempVis(n,0);
                dfs(i,graph,vis,tempVis);
                if(check(graph,tempVis)){
                    count++;
                }
            }
        }
        return count;
        
    }
};