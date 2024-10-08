class Solution {
    public String reverseWords(String s) {
        
        boolean flag =false;
        String ans = "";
        for(int i=s.length()-1 ;i>=0;i--){
            String element = "";
            while(i>=0  && s.charAt(i)!=' '){
                element = s.charAt(i)+element;
                i--;
            }
            if(!element.isEmpty()){
                if(flag == true){
                    ans = ans + " ";
                }
                ans = ans + element;
                flag =true;
            }
        }
        return ans.toString();

        
    }
}