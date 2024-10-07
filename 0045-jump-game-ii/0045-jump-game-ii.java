class Solution {
    public int jump(int[] nums) {
        int[] maxJumpsInEachStep  = new int[nums.length];
        int j = 0;
        maxJumpsInEachStep[j] = 0;
        
        if(maxJumpsInEachStep[j] >=nums.length-1 ){
            return j;
        }
        for(int i = 0;i<nums.length-1;i++ ){
            if(i>maxJumpsInEachStep[j]){
                j++;
            }
            maxJumpsInEachStep[j+1] = Math.max(maxJumpsInEachStep[j+1],nums[i] + i);
            
            if( maxJumpsInEachStep[j+1] >= nums.length-1){
                return j+1;
            }
        }
        return 1;
        
    }
}