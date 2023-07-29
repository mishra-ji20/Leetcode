class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i && nums[i]>0 && nums[i]<nums.size() &&nums[nums[i]]!=nums[i]){
                // cout<<nums[nums[i]]<<" "<<nums[i]<<" ";
                swap(nums[nums[i]],nums[i]);
            }
        }
        int a=1;
        for(int i=1;i<nums.size();i++)
        {
            // cout<<nums[i]<<" ";
            if(nums[i]!=a)
                return a;
            a++;
        }
        return nums.size();
        
    }
};