class Solution {
public:
    int maxProfit(vector<int>& arr) {
       vector<int>dp1(arr.size(),0);
        vector<int>dp2(arr.size(),0);
        int curr_min=arr[0];
        dp1[0]=0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<curr_min)
                curr_min=arr[i];
            dp1[i]=max(dp1[i-1],arr[i]-curr_min);
             // cout<<dp1[i]<<' ';
        }
         // cout<<endl;
        dp2[arr.size()-1]=0;
        int curr_max=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(curr_max<arr[i])
                curr_max=arr[i];
            dp2[i]=max(dp2[i+1],curr_max-arr[i]);
             // cout<<dp2[i]<<" ";
        }
        int ans=INT_MIN;
        for(int i=0;i<arr.size()-1;i++)
        {
            ans=max(ans,dp1[i]+dp2[i+1]);
        }
        ans=max(max(ans,dp2[0]),dp1[arr.size()-1]);
        return ans;
        
    }
};