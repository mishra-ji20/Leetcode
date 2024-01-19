class Solution {
    public int minSteps(String s, String t) {
        int[] arr1=new int[26];
        int[] arr2=new int[26];
        for(int i=0;i<s.length();i++){
            arr1[s.charAt(i)-'a']++;
            arr2[t.charAt(i)-'a']++;
        }
        int sum=0;
        for(int i=0;i<26;i++){
            if(arr1[i]>arr2[i]){
                sum=sum+arr1[i]-arr2[i];
            }
        }
        return sum;

        
    }
}