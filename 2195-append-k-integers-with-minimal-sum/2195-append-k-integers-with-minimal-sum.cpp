class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<nums.size();)
        {
            // cout<<i<<" ";
            int j=i;
            while(j<nums.size() && nums[i]==nums[j])
            {
                j++;
            }
            ans.push_back(nums[i]);
            i=j;
        }
        // for(int i=0;i<ans.size();i++)
        //     cout<<ans[i]<<"  ";
        long a=(long)k;
        long long sum=(a*(a+1))/2;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]<=a)
            {
                sum=sum-(long)ans[i];
                sum=sum+(++a);
            }
        }
        return sum;
        
    }
};