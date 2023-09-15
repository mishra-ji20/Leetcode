class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int>vis(points.size(),0);
        vector<int>cost(points.size(),INT_MAX);
        cost[0]=0;
        int sum=0;
        int i=0;
        while(sum<points.size())
        {
            vis[i]=1;
            sum=sum+1;
            for(int j=0;j<vis.size();j++)
            {
                if(vis[j]==0)
                {
                    cost[j]=min(cost[j],abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])); 
                }
            }
            int k,a=INT_MAX,ind;
            for(k=0;k<points.size();k++)
            {
                if(vis[k]==0)
                {
                    if(a>cost[k])
                    {
                        a=cost[k];
                        ind=k;
                    }
                }
            }
            i=ind;
        }
        int ans=0;
        for( i=0;i<points.size();i++){
            ans=ans+cost[i];
        }
        return ans;
       
        
    }
};