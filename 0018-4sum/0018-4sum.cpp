
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.size()<4)
            return res;
        sort(nums.begin(),nums.end());
        map<vector<int>,int>mp;
        for(int i=0;i<nums.size()-3;i++)
        {
            long long tempTarget=target-nums[i];
        
            for(int j=i+1;j<nums.size()-2;j++)
            {
                tempTarget-=nums[j];
                int k=j+1;
                int l=nums.size()-1;
                // cout<<tempTarget<<" ";
                while(k<l)
                {
                    if(nums[k]+nums[l]>tempTarget)
                    {
                        l--;
                    }
                    else if(nums[k]+nums[l]<tempTarget)
                    {
                        k++;
                    }
                    else
                    {
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        if(mp[temp]==0)
                            res.push_back(temp);
                        mp[temp]=1;
                        k++;
                        
                    }
                        
                }
                tempTarget+=nums[j];
            }
        }
        return res;
        
    }
};