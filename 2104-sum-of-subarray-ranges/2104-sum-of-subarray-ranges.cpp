class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        
            for(int i=0;i<nums.size();i++) {
                     long currMax=nums[i];
                     long currMin=nums[i];
                for(int j=i+1;j<nums.size();j++) {
                      currMax=currMax>nums[j]?currMax:nums[j];
                      currMin=currMin<nums[j]?currMin:nums[j];
                    sum+=currMax-currMin;
                }
            }
        return sum;
    }
};