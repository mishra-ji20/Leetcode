class Solution {
    public boolean canArrange(int[] arr, int k) {
        // System.out.println(arr.length);
        HashMap<Integer,Integer> modFrequency = new HashMap<>();
        
        // System.out.println(-6%5);
        for(int i=0 ;i<arr.length;i++){
            int remain = arr[i]%k;
            if(remain<0){
                modFrequency.put(remain+k,modFrequency.getOrDefault(remain+k,0)+1);
            }else{
                modFrequency.put(remain,modFrequency.getOrDefault(remain,0)+1);
            }
        }
        for(Integer key : modFrequency.keySet()){
            int firstKey = key;
            int secondKey = k-key;
            if(firstKey == secondKey){
                if(modFrequency.get(key)%2==1){
                    return false;
                }
            }else if( key!=0 && ((!Objects.equals(modFrequency.get(firstKey), modFrequency.getOrDefault(secondKey, -1))))){
                // System.out.println(key+"    "+modFrequency.get(key)+"   "+modFrequency.getOrDefault(k-key,-1));
                return false;
            }
        }
        return true;
        
    }
}