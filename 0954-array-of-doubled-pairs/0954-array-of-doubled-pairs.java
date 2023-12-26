class Solution {
    public boolean canReorderDoubled(int[] arr) {
        HashMap<Integer,Integer> mp=new HashMap<Integer,Integer>();
        Integer []nums=new Integer[arr.length];
        for(int i=0;i<arr.length;i++){
            nums[i]=arr[i];
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        Arrays.sort(nums,Comparator.comparingInt(Math::abs));
        for(int x:nums){
            if(x==0){
                continue;
            }
           if(mp.getOrDefault(x,0)>0){
               if(mp.getOrDefault(2*x,0)<=0){
                  return false; 
               }else{
                   mp.put(x,mp.getOrDefault(x,0)-1);
                   mp.put(2*x,mp.getOrDefault(2*x,0)-1);
               }
                   
           }
            
        
        
    }
        return true;
    }

};