class Solution {
    public String reverseWords(String s) {
        
        boolean flag =false;
        StringBuilder ans = new StringBuilder();
        for(int i=s.length()-1 ;i>=0;i--){
            StringBuilder element = new StringBuilder();
            while(i>=0  && s.charAt(i)!=' '){
                element.insert(0,s.charAt(i));
                
                i--;
            }
            if(!element.isEmpty()){
                if(flag == true){
                    ans.append(" ");
                }
                ans.append(element);
                flag =true;
            }
        }
        return ans.toString();

        
    }
}