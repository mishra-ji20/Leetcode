class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int [][] arr=new int[reward1.length][2];
        for(int i=0;i<reward1.length;i++){
            arr[i][0]=reward1[i]-reward2[i];
            arr[i][1]=i;
        }
        Arrays.sort(arr,new Comparator<int[]>(){
            public int compare(int []x,int[] y){
                return y[0]-x[0];
            }
        });
        
        for(int i=0;i<k;i++){
            // System.out.print(arr[i][0]+" ");
            reward2[arr[i][1]]=reward1[arr[i][1]];
        }
        int ans=0;
        for(int i=0;i<reward2.length;i++){
            ans+=reward2[i];
        }
        return ans;
        
        
        
    }
}