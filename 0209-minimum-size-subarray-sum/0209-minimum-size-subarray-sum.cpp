class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int i=0,j=0;
        long long sum=0;
        while(j<nums.size() || sum>=target)
        {
            if(sum<target)
            {
                // cout<<nums[j]<<" ";
                
                sum+=nums[j];
                j++;
            }
            else if(sum>=target)
            {
                // cout<<sum<<" "<<j<<" "<<i<<"\t";
                ans=min(j-i,ans);
                sum-=nums[i];
                i++;
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
        
    }
};