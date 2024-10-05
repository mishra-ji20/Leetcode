class Solution {
    boolean compare (int []original, int []start , int [] end ){
        for( int i =0 ;i<26;i++){
            // System.out.print(end[i]-start[i]+" ");
            if((end[i]-start[i]) != original[i]){
                return false;
            }
            
        }
        // System.out.println();
        return true;
        
    }
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length()> s2.length()){
            return false;
        }
        int [] s1Freq = new int [26];
        for(int i=0;i<s1.length();i++){
            s1Freq[s1.charAt(i)-'a']++;
        }
        int [][] s2Freq = new int [s2.length()+1][26];
        
        for(int i=0,j=0 ;j<s2.length();j++){
            
            for(int x = 0 ;x<26 ;x++){
                s2Freq[j+1][x] = s2Freq[j][x]+(s2.charAt(j)-'a'==x?1:0) ;
            }
            
            if(j+1 >= s1.length()){
                // for( int x =0 ;x<26;x++){
                //      System.out.print(s2Freq[j+1][x]+" ");
                // }
                // System.out.println();
                // for( int x =0 ;x<26;x++){
                //      System.out.print(s2Freq[i][x]+" ");
                // }
                // System.out.println();
                if(compare(s1Freq,s2Freq[i],s2Freq[j+1]) == true){
                    return true;
                }
                i++;
            }
        }
        
        return false;

        
    }
}