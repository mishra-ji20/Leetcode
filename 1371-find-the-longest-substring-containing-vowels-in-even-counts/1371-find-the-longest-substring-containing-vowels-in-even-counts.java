class Solution {
    boolean checkVowels(char ch){
        if(ch== 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u' )
            return true;
        return false;
        
    }
    int createHash(int [] arr){
        int hash =0;
        for(int i=0;i<arr.length;i++){
            hash = ((hash )<<1) | arr[i];
        }
        return hash;
    }
    public int findTheLongestSubstring(String s) {
        HashMap <Integer,Integer> lastOccurenceIndex = new HashMap<Integer,Integer>();
        lastOccurenceIndex.put(0,-1);
        int xorValue = 0;
        int ans = 0;
        int [] vowelsCount=  new int [26];
        for(int i=0 ;i<s.length();i++){
            if(checkVowels(s.charAt(i))){
                vowelsCount[s.charAt(i)-'a'] =  vowelsCount[s.charAt(i)-'a'] ^ 1;
            }
            var hash = createHash(vowelsCount); 
            if(lastOccurenceIndex.getOrDefault(hash,-2) == -2){
                // System.out.print(lastOccurenceIndex.getOrDefault(hash,-2)+" ");
                lastOccurenceIndex.put(hash,i);
            } 
            ans =Math.max(ans,i-lastOccurenceIndex.getOrDefault(hash,i)); 
            // System.out.println(hash+" "+ lastOccurenceIndex.getOrDefault(hash,-2) +"      ");
          
        }
        // System.out.println("");
        return ans;
        
        
        
    }
}