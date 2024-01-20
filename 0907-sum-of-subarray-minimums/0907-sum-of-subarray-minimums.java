class Solution {
    public int sumSubarrayMins(int[] arr) {
        ArrayList<Integer> dp=new ArrayList<>();
        Stack<Integer>st=new Stack();
        int sum=0;
        int mod=1000000007;
        for(int i=0;i<arr.length;i++){
            while(!st.empty() && arr[st.peek()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                dp.add((arr[i]*(i+1))%mod);
            }else{
                dp.add((arr[i]*(i-st.peek())+dp.get(st.peek()))%mod);
            }
            // if(sum<0)
            // System.out.println(sum+" "+dp.get(i));
            sum=((sum%mod)+dp.get(i)%mod)%mod;
            st.push(i);
        }
        return sum;
        
    }
}
