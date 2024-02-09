class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);
        int [] dp=new int [n];
        int []prevIndex=new int[n];
        int ans=0;
        dp[0]=1;
        for(int i=1;i<dp.length;i++){
            dp[i]=1;
            prevIndex[i]=i;
            int maxNum=i;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[j]>=dp[maxNum]){
                        maxNum=j;
                    }
                }
            }
            dp[i]=dp[maxNum]+1;
            prevIndex[i]=maxNum;
            // System.out.print(dp[i]+" ");
            if(dp[ans]<dp[i]){
                ans=i;
            }
        }
        List<Integer>arr=new ArrayList<Integer>();
       
        while(prevIndex[ans]!=ans){
            arr.add(nums[ans]);
            ans=prevIndex[ans];
            
        }
        arr.add(nums[ans]);
        return arr;
    }
}