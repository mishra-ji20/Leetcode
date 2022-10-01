class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>dec(nums.size(),0);
        vector<int>inc(nums.size(),0);
        inc[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=0)
            {
                inc[i]=inc[i-1]+1;
            }
            else
                inc[i]=1;
        }
        dec[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]-nums[i+1]<=0)
            {
                dec[i]=dec[i+1]+1;
            }
            else
                dec[i]=1;
        }
        vector<int>ans;
        for(int i=1;i<inc.size()-1;i++)
        {
            // cout<<inc[i]<<" "<<dec[i]<<" "<<endl;
            if(inc[i-1]>=k && dec[i+1]>=k)
                ans.push_back(i);
        }
        
        return ans;
    }
};