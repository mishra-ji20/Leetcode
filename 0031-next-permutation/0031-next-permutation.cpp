class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int currMax=-1;
        int i=nums.size()-1;
        for(i=nums.size()-1;i>=0;i--) {
            currMax=max(currMax,nums[i]);
            if(nums[i]!=currMax) {
                break;
            }
        }
        if(i<0) { 
            sort(nums.begin(),nums.end());
            return;
        }
        int j;
        for(j=nums.size()-1;j>=0;j--) {
            if(nums[i]<nums[j]){
                break;
            }
        }
        swap(nums[i],nums[j]);
        sort(nums.begin()+i+1,nums.end());
        
    }
};