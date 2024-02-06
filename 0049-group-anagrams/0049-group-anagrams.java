class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>>mp=new HashMap<>();
        for(int i=0;i<strs.length;i++){
            char[] str=strs[i].toCharArray();
            Arrays.sort(str);
            String newString=new String(str);
            List<String> temp=mp.getOrDefault(newString,new ArrayList<String>());
            temp.add(strs[i]);
            mp.put(newString,temp);
        }
        List<List<String>> ans=new ArrayList<>();
        for(Map.Entry<String,List<String>> mpElement: mp.entrySet()){
            ans.add(mpElement.getValue());
            
        }

        return ans;
    }
}