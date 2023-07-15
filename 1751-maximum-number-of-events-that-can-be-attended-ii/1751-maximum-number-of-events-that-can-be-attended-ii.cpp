class Solution {
public:
    int search(vector<vector<int>>&arr,int a){
        int i=0;
        int j=arr.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(arr[mid][0] <= a)
                i=mid+1;
            else
                j=mid-1;
        }
        return i;
    }
    bool static comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
            
        return a[0]<b[0];
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),comp);
        vector<vector<int>>dp(events.size(),vector<int>(k+1,0));
        int res=events[0][2];
        for(int i=0;i<events.size();i++)
        {
            dp[i][1]=events[i][2];
            res=max(dp[i][1],res);
        }
        for(int i=0;i<events.size();i++)
        {
            int ind=search(events,events[i][1]);
            // cout<<ind<<" ";
            
            if(i>0)
            for(int it=1;it<=k;it++)
            {
                dp[i][it]=max(dp[i][it],dp[i-1][it]-events[i-1][2]+events[i][2]);  
                res=max(res,dp[i][it]);
            }
            if(ind>=dp.size())
                continue;
            for(int j=1;j<=k;j++)
            {
                
                dp[ind][j]=max(dp[ind][j],dp[i][j-1]+events[ind][2]);
                // cout<<dp[ind][j]<<" "<<j<<" "<<i<<"\t";
                res=max(res,dp[ind][j]);
            }
            // cout<<endl;
            
        }
        return res;
        
        
        
    }
};