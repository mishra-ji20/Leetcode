class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        HashMap<String,Integer> wordsAvailable = new HashMap<String,Integer>();
        for(String words : dictionary){
            wordsAvailable.put(words,1);
        }
        int [] minLeftlaoneWords = new int [s.length()+1];
        for(int i=1 ;i<=s.length();i++){
            minLeftlaoneWords[i]= Integer.MAX_VALUE;
            String word ="";
            for(int j=i ;j>0 ;j--){
                word = s.charAt(j-1)+ word;
                minLeftlaoneWords[i] = Math.min(minLeftlaoneWords[j-1]+wordsAvailable.getOrDefault(word,word.length()+1)-1 ,minLeftlaoneWords[i]);
            }
            // System.out.println(minLeftlaoneWords[i]);
        }
        return  minLeftlaoneWords[s.length()];
    }
}