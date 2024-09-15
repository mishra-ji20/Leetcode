class Solution {
    public int findTheLongestSubstring(String s) {
        HashMap<Character,Integer> characterValue =new  HashMap<Character,Integer> ();
        characterValue.put('a',2);
        characterValue.put('e',4);
        characterValue.put('i',8);
        characterValue.put('o',16);
        characterValue.put('u',32);
        
        
        HashMap <Integer,Integer> lastOccurenceIndex = new HashMap<Integer,Integer>();
        lastOccurenceIndex.put(0,-1);
        int xorValue = 0;
        int ans = 0;
        for(int i=0 ;i<s.length();i++){
            xorValue  = xorValue ^ (characterValue.getOrDefault(s.charAt(i),0));
            if(lastOccurenceIndex.getOrDefault(xorValue,-2)==-2){
               lastOccurenceIndex.put(xorValue,i); 
            }
            ans = Math.max(ans,i - lastOccurenceIndex.getOrDefault(xorValue,i));
            // System.out.println(xorValue+" "+ans + "       ");
        }
        // System.out.println("");
        return ans;
        
        
        
    }
}