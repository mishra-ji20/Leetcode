class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        for(auto it :nums)
        {
            auto hp=lower_bound(dp.begin(),dp.end(),it);
            if(hp==dp.end())
            {
                dp.push_back(it);
                continue;
            }
            if(*hp>it)
                *hp=it;
            
        }
        return dp.size();
        
    }
};