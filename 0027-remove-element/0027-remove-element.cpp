class Solution {
public:
    void shift(vector<int> &arr, int i)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            arr[j-1]=arr[j];
        }
        arr[arr.size()-1]=-1;
    }
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        for(int i=0;i<nums.size();)
        {
            if(nums[i]==val)
            {
                shift(nums,i);
                cnt++;
            }
            else
                i++;
        }
        return nums.size()-cnt;
        
    }
};