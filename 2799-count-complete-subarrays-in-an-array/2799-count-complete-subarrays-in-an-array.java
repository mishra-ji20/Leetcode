class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int distinctCount = 0;
        HashMap<Integer,Integer> distinctElements = new HashMap<Integer,Integer> ();
        for(int i=0 ;i<nums.length;i++){
            if(distinctElements.getOrDefault(nums[i],0)==0){
                distinctCount++;
                distinctElements.put(nums[i],1);
            }
        }
        distinctElements.clear();
        int start =0;
        int end =0;
        int completeArrays = 0;
        int currDistinctElement =0;
        while(end<=nums.length){
            if(currDistinctElement == distinctCount){
                completeArrays+=nums.length-end+1;
                distinctElements.put(nums[start],distinctElements.get(nums[start])-1);
                if(distinctElements.get(nums[start]) ==0){
                    currDistinctElement --;
                }
                start++;
            }else if(end<nums.length){
                if(distinctElements.getOrDefault(nums[end],0)==0){
                    currDistinctElement++;
                }
                distinctElements.put(nums[end],distinctElements.getOrDefault(nums[end],0)+1);
                end++;
            }else{
                end++;
            }
            
        }
        return completeArrays;
        
    }
}