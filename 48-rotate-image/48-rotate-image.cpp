class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                swap(nums[i][j],nums[j][i]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0,k=nums[0].size()-1;j<k;j++,k--)
                swap(nums[i][j],nums[i][k]);
        }
        
    }
};