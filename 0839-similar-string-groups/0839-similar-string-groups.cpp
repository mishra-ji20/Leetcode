class Solution {
public:
    void dfs(int a,vector<int>graph[],vector<int>&vis)
    {
        vis[a]=1;
        for(int i=0;i<graph[a].size();i++)
        {
            if(vis[graph[a][i]]==0)
                dfs(graph[a][i],graph,vis);
        }
        
    }
    bool check(string &a,string &b)
    {
        vector<int>ans;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
                ans.push_back(i);
        }
        if(ans.size()>2)
            return 0;
        else if(ans.size()==2 && a[ans[0]]==b[ans[1]] &&b[ans[0]]==a[ans[1]])
            return 1;
        return 1;
    }
    int numSimilarGroups(vector<string>& strs) {
        vector<int>graph[strs.size()];
        for(int i=0;i<strs.size();i++)
        {
            for(int j=i+1;j<strs.size();j++)
            {
                if(check(strs[i],strs[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(strs.size(),0);
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,graph,vis);
            }
        }
        return cnt;
     
    }
};