class Solution {
public:
    static bool comp(vector<int>a1,vector<int>a2){
        if(a1[1]==a2[1]){
            return a1[0]<a2[0];
        }
        return a1[1]<a2[1];
    }
    int search(vector<vector<int>> &arr,int t){
        int i=0;
        int j=arr.size()-1;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid][1]<=t){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        long long ans=0;
        sort(rides.begin(),rides.end(),comp);
        vector<long long>dp(rides.size(),0);
        for(int i=0;i<rides.size();i++){
            int index=search(rides,rides[i][0]);
            if(index!=-1){
                dp[i]=(ans>(dp[index]+rides[i][2]+rides[i][1]-rides[i][0]))?ans:(dp[index]+rides[i][2]+rides[i][1]-rides[i][0]);
                ans=(ans>dp[i])?ans:dp[i];
            }else{
                dp[i]=(ans>rides[i][2]+rides[i][1]-rides[i][0])?ans:rides[i][2]+rides[i][1]-rides[i][0];
                ans=(ans>dp[i])?ans:dp[i];
            }
        }
        return ans;
        
        
    }
};