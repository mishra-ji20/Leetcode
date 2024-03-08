class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int ans=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
            ans=Math.max(ans,mp.get(nums[i]));
        }
        int sum=0;
        for(Map.Entry<Integer,Integer> elem : mp.entrySet()){
            if(elem.getValue()==ans){
              sum+=ans;  
            }
        }
        return sum;
    }
}