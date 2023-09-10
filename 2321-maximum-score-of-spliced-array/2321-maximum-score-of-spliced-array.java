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
    public int maximumsSplicedArray(int[] nums1, int[] nums2) {
        long sum1=0;
        long sum2=0;
        for(int i=0;i<nums1.length;i++) {
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
        int[] res=new int [nums1.length];
        for(int i=0;i<nums1.length;i++) {
            res[i]=(nums1[i]-nums2[i]); 
            // System.out.println(res[i]+" ");
        }
        long extra1=maxSum(res,-1);
        long extra2=maxSum(res,1);
        return (int)Math.max(sum1+extra1,sum2+extra2);
        
        
        
    }
}