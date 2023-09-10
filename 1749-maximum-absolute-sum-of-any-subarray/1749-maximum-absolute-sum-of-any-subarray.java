class Solution {
    int maxSum(int[] nums,int flag) {
        int i=0;
        int j=0;
        int currSum=0;
        int ans=0;
        while(j<nums.length){
            if(currSum>=0) {
                currSum+=(nums[j]*flag);
                j++;
            }else {
                currSum-=(nums[i]*flag);
                i++;
            }
            ans=Math.max(ans,currSum);
        }
        return ans;
    }
    public int maxAbsoluteSum(int[] nums) {
        return Math.max(maxSum(nums,1),maxSum(nums,-1));
    }
}