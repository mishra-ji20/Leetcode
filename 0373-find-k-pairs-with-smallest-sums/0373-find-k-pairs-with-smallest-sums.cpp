class Solution {
public:
    typedef pair<int, int> pi;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pi, vector<pi>, greater<pi> >q;
        vector<int>res(nums2.size(),0);
        for(int i=0;i<nums2.size();i++)
        {
            if(res[i]<nums1.size())   
            q.push({nums2[i]+nums1[res[i]],i});
        }
        int cnt=0;
        vector<vector<int>>sol;
        while( !q.empty() && cnt<k)
        {
                vector<int>ans;
                pi a;
                a=q.top();
                ans.push_back(nums1[res[a.second]]);
                ans.push_back(nums2[a.second]);
                q.pop();
                sol.push_back(ans);
                int i=a.second;
                res[i]++;
                if(res[i]<nums1.size())   
                q.push({nums2[i]+nums1[res[i]],i});
                cnt++;
        }
        return sol;
    }
};