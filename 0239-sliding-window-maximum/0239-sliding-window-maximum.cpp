class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int,int>>st;
        int i;
        for(i=0;i<k;i++)
        {
            st.insert({nums[i],i});
        }
        vector<int>ans;
        int j=0;
        while(i<nums.size())
        {
            auto a=st.rbegin();
            ans.push_back((a)->first);
            st.erase({nums[j],j});
            st.insert({nums[i],i});
            i++;
            j++;
        }
        auto a=st.rbegin();
        ans.push_back((a)->first);
        return ans;
        
    }
};