class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>>mp(nums.size(),vector<int>(1001,0));
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int a=nums[j]-nums[i];
                if(a<0)
                {
                    a=500+abs(a);
                }
                mp[i][a]=max(mp[i][a],mp[j][a]+1);
                ans=max(mp[i][a],ans);
            }
        }
        return ans+1;
        
    }
};