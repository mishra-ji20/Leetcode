class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer>mp1=new HashMap<>();
        HashMap<Integer,Integer>mp2=new HashMap<>();
        for(int i=0;i<nums1.length;i++){
            mp1.put(nums1[i],1);
        }
        for(int i=0;i<nums2.length;i++){
            if(mp1.getOrDefault(nums2[i],0)>=1){
                mp1.put(nums2[i],mp1.getOrDefault(nums2[i],0)+1);
            }
        }
        ArrayList<Integer>arr1=new ArrayList<>();
        for(Map.Entry<Integer,Integer> elem : mp1.entrySet()){
            if(elem.getValue()>1){
                arr1.add(elem.getKey());
            }
        }
        int [] ans=new int[arr1.size()];
        for(int i=0;i<arr1.size();i++){
            ans[i]=arr1.get(i);
        }
        return ans;
        

        
        
    }
}