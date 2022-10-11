class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();)
        {
            int a=1;
            int j=i;
            while(j<nums.size() && a!=0)
            {
                int b=1;
                if(j<nums.size())
                    b=nums[j]>0?1:(nums[j]<0)?-1:0;
                a=a*b;
                if(a>0)
                {
                    ans=max(ans,j-i+1);
                }
                j++;
            }
            i=j;
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();)
        {
            int a=1;
            int j=i;
            while(j<nums.size() && a!=0)
            {
                int b=1;
                if(j<nums.size())
                    b=nums[j]>0?1:(nums[j]<0)?-1:0;
                a=a*b;
                if(a>0)
                {
                    ans=max(ans,j-i+1);
                }
                j++;
            }
            i=j;
        }
        
        return ans;
        
    }
};