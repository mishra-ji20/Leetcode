class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();)
        {
            int j=i;
            while(j<nums.size() && nums[i]==nums[j])
            {
                j++;
            }
            nums[k]=nums[i];
            k++;
            i=j;
            
        }
        return k;
        
        
    }
};