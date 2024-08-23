class Solution {
    public boolean wordPattern(String pattern, String s) {
        

        HashMap<Character,String>patternMap = new HashMap<Character,String>();
        HashMap<String,Character>strMap = new HashMap<String,Character>(); 
        
        int index=0;
        for(int i=0 ;i<pattern.length();i++){
            StringBuilder  str = new StringBuilder();
            if(index>=s.length()){
                return false;
            }
            while(index<s.length() && s.charAt(index)!=' '){
                str.append(s.charAt(index));
                index++;
            }
            // System.out.println(strMap.getOrDefault(str.toString(),'1'));
            if(patternMap.getOrDefault(pattern.charAt(i),"-1") == "-1" && strMap.getOrDefault(str.toString(),'1') == '1'){
                // System.out.println(strMap.getOrDefault(str,'1'));
                patternMap.put(pattern.charAt(i),str.toString());
                strMap.put(str.toString(),pattern.charAt(i));
                
            }else if(!( patternMap.getOrDefault(pattern.charAt(i),"-1").equals(str.toString()) &&  strMap.getOrDefault(str.toString(),'1').equals(pattern.charAt(i))  )){
                return false;
            }
            index++;
        }
        if(index >= s.length())
        return true;
        
        return false;
        
    }
}