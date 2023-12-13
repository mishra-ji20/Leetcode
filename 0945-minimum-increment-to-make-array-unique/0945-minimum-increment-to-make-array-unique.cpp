class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,currMax=nums[0]-1;
        for(int i=0;i<nums.size();){
            int j=i;
            while(j<nums.size() && nums[i]==nums[j]){
                j++;
            }
            int a=nums[i]<=currMax?currMax+1-nums[i]:0;
            int n=j-i;
            ans=ans+((n)*((2*a)+(n-1)))/2;
            currMax=max(currMax,a+nums[i]+n-1);
            i=j;
        }
        return ans;
        
    }
};