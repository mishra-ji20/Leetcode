class Solution {
    Boolean checkVowel(char a){
        return a=='a'||a=='e'||a=='i'||a=='o'||a=='u' || a=='A'|| a=='E' || a=='I' || a=='O' || a=='U';
    }
    public boolean halvesAreAlike(String s) {
        int cnt1=0,cnt2=0;
        for(int i=0,j=(s.length())/2;i<(s.length())/2;i++,j++){
            if(checkVowel(s.charAt(i))){
                cnt1++;
            }
            if(checkVowel(s.charAt(j))){
                cnt2++;
            }
        }
        return cnt1==cnt2;
        
    }
}