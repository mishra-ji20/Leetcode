class Solution {
public:
    int buyChoco(vector<int>& nums, int money) {
        sort(nums.begin(),nums.end());
        int x=nums[0]+nums[1]<=money?nums[0]+nums[1]:0;
        
            return money-x;
        
    }
};