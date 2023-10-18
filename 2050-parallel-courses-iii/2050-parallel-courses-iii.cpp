class Solution {
public:
    long recur(vector<int>graph[],int a,vector<long> &dp,vector<int> &time) {
        // cout<<a<<" ";
        if(dp[a]!=LONG_MIN) {
            return dp[a];
        }
        long ans=0;
        for(int i=0;i<graph[a].size();i++) {
            int x=recur(graph,graph[a][i],dp,time);
            ans=ans>x?ans:x;   
        }
        dp[a]=ans+time[a-1];
        return dp[a];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>graph[n+1];
        vector<int>vis(n+1,0);
        for(int i=0;i<relations.size();i++) {
            graph[relations[i][1]].push_back(relations[i][0]);
            vis[relations[i][0]]=1;
        }
        vector<long>dp(n+1,LONG_MIN);
        long ans=0;
        for(int i=1;i<=n;i++) {
            if(vis[i]==0) {
                ans=ans>recur(graph,i,dp,time)?ans:recur(graph,i,dp,time);
            }
        }
        return ans;
    }
};