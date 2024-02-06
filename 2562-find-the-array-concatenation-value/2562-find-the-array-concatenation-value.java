class Solution {
    public long findTheArrayConcVal(int[] nums) {
        long ans=0L;
        int i=0,j=nums.length-1;
        for(;i<j;i++,j--){
            int x=nums[j];
            while(x>0){
                nums[i]=nums[i]*10;
                x=x/10;
            }
            // System.out.print((long)nums[i]+(long)nums[j]+" ");
            ans=ans+(long)nums[i]+(long)nums[j];
        }
        if(i==j){
            ans+=nums[i];
        }
        return ans;
    }
}