class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int []prefixSum =new int [arr.length];
        int sum=0;
        prefixSum[0]=arr[0];
        for(int i=1;i<arr.length;i++){
            prefixSum[i]=prefixSum[i-1] + arr[i];
        }
        sum=prefixSum[arr.length-1];
        if((sum%3) != 0){
            return false;
        }
        int[] num = {sum/3,(sum/3)*2};
        int j =0;
        for(int i=0 ;i< prefixSum.length -1 && j<2;i++){
            if(prefixSum[i]== num[j]){
                j++;
            }
        }
        if(j==2){
            return true;
        }else{
            return false;
        }
    }
}