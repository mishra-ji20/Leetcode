class Solution {
    
    public int findSubstringInWraproundString(String s) {
        int [] longestSubstringofEachAlphabet = new int[26];
        char [] charAdjacent = new  char[26];
        for(int i=1;i<26;i++){
            charAdjacent[i]=(char)('a'+(i-1));
        }
        charAdjacent[0]='z'; 
        for(int i=0;i<s.length();){
            int j= i+1;
            int count =1;
            char startChar=s.charAt(i);
            while(j<s.length() && charAdjacent[s.charAt(j)-'a']== s.charAt(i)){
                i++;
                j++;
                count++;
            }
            int index =startChar-'a';
            do{
                longestSubstringofEachAlphabet[(index%26)]=Math.max(longestSubstringofEachAlphabet[(index%26)],count);
                index++;
                count--;
            }while(count> 0 && (startChar-'a')!= (index%26));
            i++;
            
        }
        int  ans =0;
        for(int i=0 ;i<26;i++){
            int res = longestSubstringofEachAlphabet[i];
            // System.out.print(res+" ");
            ans += res;
        }
        // System.out.println();
        return ans;
        
    }
}