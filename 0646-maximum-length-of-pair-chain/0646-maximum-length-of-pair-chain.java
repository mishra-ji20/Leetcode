class Solution {
    static int search(List<Integer>arr, int target)
    {
        int i=0;
        int j=arr.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(arr.get(mid)==target)
                return mid;
            if(arr.get(mid)>target)
                j=j-1;
            else
                i=i+1;
        }
        return i;
        
    }
     public static void sortbyColumn(int arr[][], int col)
    {
       Arrays.sort(arr, (a, b) -> Integer.compare(a[col],b[col])); // increasing order  
    }
    public int findLongestChain(int[][] pairs) {
        sortbyColumn(pairs,0);
        List<Integer> dp=new ArrayList<Integer>();
        dp.add(pairs[0][1]);
        int ans=1;
        for(int i=1;i<pairs.length;i++)
        {
            int index=search(dp,pairs[i][0]);
           
            
            if(index==dp.size())
                dp.add(pairs[i][1]);
            else
                dp.set(index,Math.min(dp.get(index),pairs[i][1]));
            // System.out.println(index +" "+dp.size());
            ans=Math.max(ans,dp.size());
            
        }
        return ans;
        
        
        
    }
}