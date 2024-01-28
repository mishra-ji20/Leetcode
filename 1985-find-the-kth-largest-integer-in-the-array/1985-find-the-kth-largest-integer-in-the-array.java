class Solution {
   
           public int compare(String s1 , String s2){
               if(s2.length()!=s1.length()){
                  return s2.length()-s1.length(); 
               }
               
                for(int i=0,j=0;i<s1.length() && j<s2.length();j++,i++){
                    if(s2.charAt(j)==s1.charAt(i)){
                        continue;
                    }else{
                        return s2.charAt(j)-s1.charAt(i);
                    }
                }
               return 0;
 
    }
    public String kthLargestNumber(String[] nums, int k) {
        PriorityQueue<String> q=new PriorityQueue<String>(new Comparator<String>(){
           public int compare(String s2 , String s1){
               if(s2.length()!=s1.length()){
                  return s2.length()-s1.length(); 
               }
               int i=0,j=0;
                for(;i<s1.length() && j<s2.length();j++,i++){
                    if(s2.charAt(j)==s1.charAt(i)){
                        continue;
                    }else{
                        return s2.charAt(j)-s1.charAt(i);
                    }
                }
               return 0;
               
            } 
        });
        for(int i=0;i<nums.length;i++){
            if(q.size()<k){
                q.add(nums[i]);
            }else if(compare(q.peek(),nums[i])>0){
                q.poll();
                q.add(nums[i]); 
            }
        }
        // while(!(q.isEmpty()))
        // System.out.println(q.poll());
        return q.poll();
        
       
        
    }
}