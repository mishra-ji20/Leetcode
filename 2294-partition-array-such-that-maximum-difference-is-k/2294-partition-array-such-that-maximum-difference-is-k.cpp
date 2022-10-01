class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)
            return 1;
        
        int i=0,j=1;
        int ans=0;
        while(i<nums.size())
        {
            while(j<nums.size() && nums[j]-nums[i]<=k)
            {
                j++;
            }
           ans++;
            i=j;
            j++;
        }
        return ans;
        
        
    }
};