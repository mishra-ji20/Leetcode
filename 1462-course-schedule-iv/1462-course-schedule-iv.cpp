class Solution {
public:
    bool search(vector<int>nums,int target){
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]>target) {
                h=mid-1;
                
            }else{
                l=mid+1;
            }
            
        }
        return false;
        
    }
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
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int>graph[n];
        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,i,graph,vis,ans);
        }
        vector<bool>res;
        for(int i=0;i<queries.size();i++){
            res.push_back(search(ans[queries[i][1]],queries[i][0]));
        }
        return res;
        
    }
};