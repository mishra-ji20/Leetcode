class Solution {
public:
    int search (vector<int>& arr, int a)
    {
        int l=0;
        int h=arr.size()-1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(arr[mid]>=a)
            {
                h=mid;
            }
            else
                l=mid+1;
        }
        return l;
    }
    int hIndex(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=0;
        int b=nums[nums.size()-1];
        int ans=0;
        while(a<=b)
        {
            int mid=(a+b)/2;
             // cout<<search(nums,mid)<<" ";
            if(nums.size()-search(nums,mid)>=mid)
            {
                ans=mid;
                a=mid+1;
            }
            else
                b=mid-1;
        }
        
        return ans;
        
    }
};