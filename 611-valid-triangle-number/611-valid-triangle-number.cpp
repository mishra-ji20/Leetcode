class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
       
        vector<int>arr;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
                arr.push_back(nums[i]);
                
        }
        if(arr.size()<3)
            return 0;
        sort(arr.begin(),arr.end());
        int k=2;
        int ans=0;
       for(int i=0;i<arr.size()-2;i++)
       {
           for(int j=i+1;j<arr.size()-1;j++)
           {
               auto itr=lower_bound(arr.begin(),arr.end(),arr[j]+arr[i]);
               ans=ans+(itr-(arr.begin()+j))-1;
           }
       }
        return ans;
    }
};