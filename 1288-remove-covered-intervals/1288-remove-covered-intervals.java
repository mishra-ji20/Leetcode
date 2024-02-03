class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals,new Comparator<int[]>(){
            public int compare(int[]arr1,int[]arr2){
                if(arr1[0]==arr2[0]){
                    if(arr1[1]<arr2[1]){
                        return 1;
                    }else {
                        return -1;
                    }
                }else if(arr1[0]>arr2[0]){
                    return 1;
                }else{
                    return -1;
                }
            }
        });
        int currMax=-1;
        int ans=0;
        for(int i=0;i<intervals.length;i++){
            if(intervals[i][1]<=currMax){
                ans++;
            }else{
                currMax=intervals[i][1];
            }
        }
        return intervals.length-ans;
    }
}