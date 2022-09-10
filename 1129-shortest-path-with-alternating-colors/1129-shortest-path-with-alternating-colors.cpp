class Solution {
public:
    void bfs(vector<int> graph1[], vector<int>graph2[],vector<int>&ans,int n)
    {
        vector<int>vis1(n,0);
        vector<int>vis2(n,0);
        queue<int>q;
        q.push(0);
        vis1[0]=1;
        int count=1;
        while(!q.empty())
        {
            
            int b=q.size();
            while(b--)
            {
                int a=q.front();
                if(count%2)
                {
                    for(int i=0;i<graph1[a].size();i++)
                    {
                        if(vis1[graph1[a][i]]==0)
                        {
                            q.push(graph1[a][i]);
                            vis1[graph1[a][i]]=1;
                            ans[graph1[a][i]]=min(ans[graph1[a][i]],count);
                        }
                    }
                }
                if(count%2==0)
                {
                    for(int i=0;i<graph2[a].size();i++)
                    {
                        if(vis2[graph2[a][i]]==0)
                        {
                            q.push(graph2[a][i]);
                            vis2[graph2[a][i]]=1;
                            ans[graph2[a][i]]=min(ans[graph2[a][i]],count);
                        }
                    }
                }
                q.pop();
            }
            count++;
        }
        
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<int>graph1[n];
        vector<int>graph2[n];
        for(int i=0;i<red.size();i++)
        {
            graph1[red[i][0]].push_back(red[i][1]);
        }
        for(int i=0;i<blue.size();i++)
        {
            graph2[blue[i][0]].push_back(blue[i][1]);
        }
        vector<int>ans(n,INT_MAX);
        ans[0]=0;
        bfs(graph1,graph2,ans,n);
        bfs(graph2,graph1,ans,n);
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        }
        return ans;
        
    }
};