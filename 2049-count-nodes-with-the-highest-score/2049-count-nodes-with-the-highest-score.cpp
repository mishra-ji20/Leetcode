class Solution {
public:
    int dfs(int a,vector<vector<int>>&edge,vector<vector<int>>&sz){
        
        for(int i=0;i<edge[a].size();i++)
        {
            sz[a][i]=dfs(edge[a][i],edge,sz);
        }
        return sz[a][0]+sz[a][1]+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>>edge(parents.size());
        vector<vector<int>>sz(parents.size(),vector<int>(2,0));
        unordered_map<long long ,int>mp;
        for(int i=0;i<parents.size();i++)
        {
            if(parents[i]!=-1)
            {
                edge[parents[i]].push_back(i);
            }
        }
        dfs(0,edge,sz);
        long long int ans=-1;
        for(int i=0;i<edge.size();i++)
        {
            long long int pro=1;
            if(sz[i][0])pro*=(long)sz[i][0];
            if(sz[i][1])pro*=(long)sz[i][1];
            
            if(parents[i]!=-1)
            {
                pro*=(sz[0][0]+sz[0][1]-sz[i][0]-sz[i][1]);
            }
            // cout<<i<<" "<<pro<<"   ";
            mp[pro]++;
            ans=max(ans,pro);
        }
        return mp[ans];
        
    }
};