class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int [] prevCost = {triangle.get(0).get(0)};
        int ans = Integer.MAX_VALUE;
        for(int i = 0 ;i< triangle.size()-1 ;i++){
            // System.out.println(prevCost.length);
            // System.out.println(triangle.get(i+1).size());
           int[] currCost = new int[triangle.get(i+1).size()];
            for (int j =0 ;j<currCost.length;j++){
                currCost[j]= Integer.MAX_VALUE;
            }
            for(int j=0 ;j<prevCost.length;j++){
                
                currCost[j] = Math.min(currCost[j],(prevCost[j]+triangle.get(i+1).get(j)));
                currCost[j+1] = Math.min(currCost[j+1],(prevCost[j]+triangle.get(i+1).get(j+1)));
                // System.out.print(currCost[j]+" "+ currCost[j+1]+"         ");
                
            }
            // for(int j =0 ;j<currCost.length;j++){
            //     System.out.print(currCost[j]+" ");
            // }
            // System.out.println();
            prevCost = currCost;
        }
        for(int i = 0 ;i<prevCost.length;i++){
            ans = Math.min(prevCost[i],ans);
        }
        return ans;
        
    }
}