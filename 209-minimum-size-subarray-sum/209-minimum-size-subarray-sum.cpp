class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<long long int>arr(nums.size()+1,0);
        arr[0]=0;
        for(int i=1;i<arr.size();i++)
        {
            arr[i]=arr[i-1]+nums[i-1];
        }
        int j=0;
        int res=INT_MAX;
        for(int i=1;i<arr.size();)
        {
            while(i<arr.size() && arr[i]-arr[j]<target)
            {
                i++;
            }
            if(i==arr.size())
                break;
            while(arr[i]-arr[j]>=target && j<i)
            {
                res=min(res,i-j);
                j++;
            }
            
        }
        if(res==INT_MAX)
            return 0;
        else
            return res;
        
    }
};