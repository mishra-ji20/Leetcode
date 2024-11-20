class Solution {
    
    public long maximumSubarraySum(int[] nums, int k) {
        HashMap<Integer,Integer>  mp = new HashMap<>();
        int i =0 ,j=0 ;
        long sum = 0;
        long ans =0 ;
        while(j<nums.length){
            while(j<nums.length && j-i<k){
                if(mp.getOrDefault(nums[j],0)==0){
                    sum += (long)(nums[j]);
                    mp.put(nums[j],1);
                    j++;
                }else{
                    mp.put(nums[i],0);
                    sum = sum - nums[i];
                    i++;
                }
            }
            if(j-i == k){
                // System.out.println(i+ " " + j + "   sum: "+ sum);
                ans = ans>sum ? ans:sum;
            }
            mp.put(nums[i],0);
            sum = sum - nums[i];
            i++;
        }
        return ans;
         
    }
}