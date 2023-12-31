class Solution {
public:
    static bool comp(vector<int> &a ,vector<int> &b){
        return a[0]<b[0];
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<vector<int>>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end(),comp);
        int cnt=0;
        vector<int>ans(nums.size(),0);
        for(int i=0;i<arr.size();){
            int j=i;
            while(j<arr.size() && arr[j][0]==arr[i][0]){
                // cout<<arr[j][1]<<" ";
                ans[arr[j][1]]=cnt;
                j++;  
            }
            cnt=j;
            i=j;
            
        }
        return ans;
        
    }
};