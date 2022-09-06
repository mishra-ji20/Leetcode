class Solution {
public:
     void dfs(vector<vector<int>>&graph,int s,int t,vector<int>&ans,vector<vector<int>>&res)
    {
        if(s==t){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<graph[s].size();i++)
        {
            ans.push_back(graph[s][i]);
            dfs(graph,graph[s][i],t,ans,res);
                ans.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>ans;
        vector<vector<int>>res;
        ans.push_back(0);
        dfs(graph,0,graph.size()-1,ans,res);
        return res;
        
    }
};