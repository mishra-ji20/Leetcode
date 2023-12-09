class Solution {
public:
    bool check(vector<int>&arr,int x,int &res){
        for(int i=0;i<arr.size();i++){
            
            int req=arr[i]/x;
            int left=arr[i]%x;
            // cout<<req<<' '<<left<<" ";
            if(left!=0 && left<x-1){
                if(x-1-left>req){
                    return false;
                }
            }
            res=res+req+(left>0?1:0);
        }
        // cout<<res<<endl;
        return true;
        
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>arr;
        int mi=INT_MAX;
        for(auto &it : mp){
            arr.push_back(it.second);
            mi=min(mi,it.second);
        }
        int ans=INT_MAX;
        for(int i=mi+1;i>=2;i--){
            int res=0;
            if(check(arr,i,res)){
                ans=min(ans,res);
            }
            
        }
        return ans;
        
    }
};