class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1]!=nums[i]){
               ans=ans+(nums.size()-i); 
            }
        }
        return ans;
        
        
    }
};