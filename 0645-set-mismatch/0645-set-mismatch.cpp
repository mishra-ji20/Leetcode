class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>mp(nums.size()+1,0);
        vector<int>sol;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]){
                sol.push_back(nums[i]);
            }
            mp[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(mp[i]==0)
                sol.push_back(i);
        }
        return sol;
       
    }
};