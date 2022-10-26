class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        int flag=0;
        if(nums.size()<2)
            return false;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(i<nums.size()-1 && nums[i]%k==0 && nums[i+1]%k==0 )
                flag++;
            nums[i]=nums[i]%k+sum;
            mp[nums[i]]=1;
            sum=nums[i];
        }
        if(flag){
            return true;
        }
        for(int i=0;i<nums.size();i++)
        {
            int a=k;
            if(nums[i]%k==0 && i!=0){
                return true;
            }
            else
            {
                while(nums[i]-a>=0)
                {
                    if(mp[nums[i]-a]==1){
                        return true;
                    }
                    a=a+k;
                }
            }
        }
        return false;
       
    }
};