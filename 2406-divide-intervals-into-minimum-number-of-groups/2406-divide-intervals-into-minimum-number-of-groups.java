class Solution {
    public int minGroups(int[][] intervals) {
        Arrays.sort(intervals,new Comparator<int[]>(){
            public int compare(int [] first,int [] second){
                if(first[0]!= second [0]){
                    return Integer.compare(first[0],second[0]);
                }else{
                    return Integer.compare(first[1],second[1]);
                }
            }
        });
        
        PriorityQueue <Integer> smallestGroupEnd = new  PriorityQueue <Integer> ( new Comparator<Integer>(){
            public int compare(Integer first,Integer second){
                return first.compareTo(second);
            }
        });
        smallestGroupEnd.add(intervals[0][1]);
        for(int i=1 ;i<intervals.length;i++){
            if(smallestGroupEnd.peek()<intervals[i][0]){
                smallestGroupEnd.poll();
            }
            smallestGroupEnd.add(intervals[i][1]);
        }
        return smallestGroupEnd.size();
        
        
        
    }
}