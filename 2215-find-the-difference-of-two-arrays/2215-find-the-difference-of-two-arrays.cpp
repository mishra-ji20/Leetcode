class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
           
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
           
        }
        
        vector<vector<int>>ans(2);
        for(auto it:mp1)
        {
            if(mp2[it.first]==0)
                ans[0].push_back(it.first);
        }
        for(auto it:mp2)
        {
            if(mp1[it.first]==0)
                ans[1].push_back(it.first);
        }
        return ans;
    }
};