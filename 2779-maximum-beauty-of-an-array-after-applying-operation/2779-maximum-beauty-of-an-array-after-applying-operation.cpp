class Solution {
public:

    int search1(vector<int> &nums,int t,int k)
    {
        int i=0;
        int j=nums.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(nums[mid]+k<=t)
            {
                i=mid+1;
            }
            else
                j=mid-1;
        }
        return i;
        
    }
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=1;
        for(int i=0;i<nums.size();i++)
        {
            int a=search1(nums,nums[i]+k,-k);
            res=max(res,a-i);
            
        }
        return res;
        
    }
};