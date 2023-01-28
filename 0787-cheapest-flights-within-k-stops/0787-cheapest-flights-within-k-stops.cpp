class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int s) {
        vector<vector<long>>graph[n];
        for(int i=0;i<flights.size();i++)
        {
            vector<long>arr {flights[i][1],flights[i][2]};
            graph[flights[i][0]].push_back(arr);
        }
        vector<vector<long>>dp(n,vector<long>(s+2,INT_MAX));
        queue<int>q;
        q.push(src);
        int k=0;
        for(int i=0;i<=s;i++)
        {
            dp[src][i]=0;
        }
        int ans=INT_MAX;
        while(!q.empty())
        {
            int b=q.size();
            while(b--){
            auto a=q.front();
            q.pop();
            // cout<<a<<" ";
            for(int i=0;i<graph[a].size();i++)
            {
                // cout<<graph[a][i][0]<<" "<<dp[a][k]<<" "<<graph[a][i][1]<<endl;
                if(k<=s){
                   // cout<<dp[graph[a][i][0]][k+1]<<" "<<dp[a][k]<<" "<<graph[a][i][1]<<" "; 
                if(dp[graph[a][i][0]][k+1]>dp[a][k]+graph[a][i][1])
                {
                   
                    dp[graph[a][i][0]][k+1]=dp[a][k]+graph[a][i][1];
                    if(graph[a][i][0]==dst)
                        ans=ans<dp[graph[a][i][0]][k+1]?ans:dp[graph[a][i][0]][k+1];
                        else
                    q.push(graph[a][i][0]);
                }
                }
            }
            }
            k++;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};