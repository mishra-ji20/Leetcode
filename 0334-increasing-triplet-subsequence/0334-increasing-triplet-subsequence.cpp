class Solution {
public:
   
       bool increasingTriplet(vector<int>& nums) {
        vector<int> dp;
        for (auto n : nums)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), n);
           
            if (iter == dp.end())
            {
                dp.push_back(n);
                if (dp.size() == 3)
                    return true;
                continue;
            }
            // cout<<*iter<<' ';
            if (*iter > n)
                *iter = n;
        }
        return false;
    }
        
        
        
    
};