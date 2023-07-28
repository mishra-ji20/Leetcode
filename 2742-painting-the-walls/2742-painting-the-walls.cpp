class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<int>dp(cost.size()+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<cost.size();i++)
        {
            vector<int>dpt(cost.size()+1,INT_MAX);
            for(int j=0;j<=cost.size();j++)
            {
                
                int k=j+time[i]+1>=cost.size()?cost.size():j+time[i]+1;
                if(dp[j]!=INT_MAX){
                    // if(j==2)
                    //     cout<<dpt[k]<<" "<<dp[j]+cost[i]<<" "<<k<<" ";
                    dpt[k]=min(dpt[k],dp[j]+cost[i]);
                }
                // cout<<dpt[j]<<" ";
            }
            // cout<<endl;
            for(int a=0;a<=cost.size();a++){
                dp[a]=min(dp[a],dpt[a]);
                // cout<<dp[a]<<" ";
            }
            // cout<<endl;
            // cout<<dp[i+1]<<" ";
        }
        // cout<<endl;
        return dp[cost.size()];
        
    }
};