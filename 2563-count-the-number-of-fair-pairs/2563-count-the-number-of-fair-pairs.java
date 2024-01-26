class Solution {
    int getMinInd(int[] nums,int start,int target){
        int end=nums.length-1;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>=target){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
        
    }
    int getMaxInd(int[] nums,int start,int target){
        int end=nums.length-1;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]<=target){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
        
    }
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans=0L;
        for(int i=0;i<nums.length-1;i++){
            int x=getMinInd(nums,i+1,lower-nums[i]);
            int y=getMaxInd(nums,i+1,upper-nums[i]);
            if(x!=-1 && y!=-1){
              ans+=(long)((y-x)+1);  
            }
        }
        return ans;
        
        
    }
}