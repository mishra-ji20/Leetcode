class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int count=0;
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]+nums[j]>limit)
            {
                j--;
            }
            else{
                i++;
                j--;
            }
            count++;
        }
        return count;
    
    }
};