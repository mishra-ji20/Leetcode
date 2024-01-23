class Solution {
    public int recur(List<String>arr,int curr,int val,int []mp){
        int ans=val;
        
        
        for(int i=curr;i<arr.size();i++){
            // System.out.println(curr+" "+i);
            int []currMp=new int[26];
            for(int cnt=0;cnt<26;cnt++){
                currMp[cnt]=mp[cnt];
            }
            int flag=0;
            for(int j=0;j<arr.get(i).length();j++){
                char ch=arr.get(i).charAt(j);
                if(currMp[ch-'a']==1){
                    flag=1;
                    break;
                }else{
                    currMp[ch-'a']++;
                }
            }
            if(flag==0){
                ans=Math.max(ans,recur(arr,i+1,val+arr.get(i).length(),currMp));
            }
        }
        return ans;
        
    }
    public int maxLength(List<String> arr) {
        int [] mp=new int[26];
        return recur(arr,0,0,mp);
          
    }
}