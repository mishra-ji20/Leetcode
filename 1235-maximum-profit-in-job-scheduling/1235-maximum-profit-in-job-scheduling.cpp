class Solution {
public:
    int search(vector<vector<int>> &arr,int t){
        int i=0;
        int j=arr.size()-1;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid][0]<=t){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>arr;
        for(int i=0;i<startTime.size();i++){
            arr.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        vector<int>dp(arr.size(),0);
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int index=search(arr,arr[i][1]);
            // cout<<index<<" ";
            if(index!=-1){
                dp[i]=max(ans,dp[index]+arr[i][2]);
                ans=dp[i];
                
            }else{
                dp[i]=max(ans,arr[i][2]);
                ans=dp[i];
            }
            // cout<<endl;
            
        }
        return ans;
        
    }
};