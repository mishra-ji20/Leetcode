class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> q=new PriorityQueue<Integer>(new Comparator<Integer>(){
            public int compare(Integer x,Integer y){
                if(x>y){
                    return 1;
                }else{
                    return -1;
                }
            }
        });
        int greaterSum=0;
        int i=0;
        for(i=1;i<heights.length;i++){
            if(heights[i]>heights[i-1]){
                if(q.size()<ladders){
                    q.add(heights[i]-heights[i-1]);
                }else{
                    int useBricks=heights[i]-heights[i-1];
                    if(!(q.isEmpty()) && q.peek()<heights[i]-heights[i-1]){
                        useBricks=q.poll();
                        q.add(heights[i]-heights[i-1]);
                    }
                    if(useBricks>bricks){
                        return i-1;
                    }else{
                        bricks-=useBricks;
                    }
                }
            }
        }
        return i-1;
    }
}