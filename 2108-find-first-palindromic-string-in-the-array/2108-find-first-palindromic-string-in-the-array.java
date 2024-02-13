class Solution {
    public String firstPalindrome(String[] words) {
        for(int i=0;i<words.length;i++){
            int flag=0;
            for(int j=0,k=words[i].length()-1;j<k;j++,k--){
                if(words[i].charAt(j)!=words[i].charAt(k)){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return words[i];
            }
        }
        return "";
        
    }
}