class Solution {
    
    public int binarySearch(int [][] items, int k){
        int start = 0 ;
        int end = items.length-1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(k>=items[mid][0]){
                ans = mid;
                start = mid+1;
            }else{
                end = mid -1;
            }
        }
        return ans;
        
    }
    public int[] maximumBeauty(int[][] items, int[] queries) {
        int [] queriesAnswer = new int [queries.length];
        Arrays.sort(items,new Comparator<int[]>(){
            public int compare (int []arr1, int [] arr2){
                if(arr1[0]<arr2[0]){
                    return -1;
                }else {
                    return 1;
                }
            }
            
        });
        for ( int i = 1 ;i<items.length;i++){
            items[i][1]= Math.max(items[i][1],items[i-1][1]);
        }
        
        for(int i = 0 ; i<queries.length;i++){
            int x = binarySearch(items,queries[i]);
            // System.out.print(x+" ");
            if(x == -1){
                queriesAnswer[i]= 0;
            }else{
                queriesAnswer[i]=items[x][1];
            }
        }
//         System.out.println();
        
//         for(int i =0 ;i<items.length;i++){
//             System.out.println(items[i][0]+" "+items[i][1]);
//         }
        return queriesAnswer;
    }
}