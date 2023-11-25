class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        long sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        long prefix=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            long x=(sum-nums[i]-prefix)-((nums.size()-i-1)*(nums[i]));
            long y=((i)*(nums[i]))-prefix;
            prefix=prefix+nums[i];
            ans.push_back(x+y);
        }
        return ans;
        
    }
};