class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        HashMap<Integer,Integer> hm=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
        }
        ArrayList<Integer>nums=new ArrayList<>();
        for(Map.Entry<Integer,Integer> elem: hm.entrySet()){
            nums.add(elem.getValue());
        }
        Collections.sort(nums);
        for(int i=0;i<nums.size();i++) {
            if(nums.get(i)<=k){
                k-=nums.get(i);
            }else{
                return nums.size()-i;
            }
        }
        return 0;
        
    }
}