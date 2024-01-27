class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        ArrayList<Integer>list1=new ArrayList<>();
        ArrayList<Integer>list2=new ArrayList<>();
        for(int i=0;i<s.length();i++){
            if(i+a.length()<=s.length()){
                if(s.substring(i,i+a.length()).equals(a)){
                    list1.add(i);
                    // System.out.println(i);
                }
            }
            if(i+b.length()<=s.length()){
                if(s.substring(i,i+b.length()).equals(b)){
                    list2.add(i);
                    // System.out.println(i);
                }
            }
        }
        List<Integer>ans=new ArrayList<Integer>();
        for(int i=0,j=0;i<list1.size() && j<list2.size();){
            
            if(list1.get(i)-list2.get(j)>k){
                j++;
            }
            else if(list1.get(i)-list2.get(j)>=-k && list1.get(i)-list2.get(j)<=k ){
                ans.add(list1.get(i));
                i++;;
            }else{
                i++;
            }
            
        }
        return ans;
        
    }
}