
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {

        PriorityQueue<ArrayList<Integer>> minQueue = new PriorityQueue<ArrayList<Integer>>(new Comparator<ArrayList<Integer>>(){
            
            public int compare(ArrayList<Integer> first , ArrayList<Integer> second){
                return -(first.get(0).compareTo(second.get(0)));
            }
        });
        PriorityQueue<ArrayList<Integer>> maxQueue = new PriorityQueue<ArrayList<Integer>>(new Comparator<ArrayList<Integer>>(){
            public int compare(ArrayList<Integer> first , ArrayList<Integer> second){
                return first.get(0).compareTo(second.get(0));
            }
        });
        for(int index = 0 ;index < arrays.size();index++){
            if(minQueue.size()<2){
                minQueue.add(new ArrayList<Integer>(List.of(arrays.get(index).get(0),index)));
            }else{
               
                
                int currMin = arrays.get(index).get(0)<minQueue.peek().get(0)?arrays.get(index).get(0):minQueue.peek().get(0);
                minQueue.poll();
                minQueue.add(new ArrayList<Integer>(List.of(currMin,index))); 
                // System.out.println(minQueue);
            }
            if(maxQueue.size()<2){
                maxQueue.add(new ArrayList<Integer>(List.of(arrays.get(index).get(arrays.get(index).size()-1),index)));
            }else{
                int currMax = arrays.get(index).get(arrays.get(index).size()-1)>maxQueue.peek().get(0)?arrays.get(index).get(arrays.get(index).size()-1):maxQueue.peek().get(0);
                maxQueue.poll();
                maxQueue.add(new ArrayList<>(List.of(currMax,index)));   
            } 
        }
//         while(!minQueue.isEmpty()){
//            System.out.print(minQueue.poll().get(0)+" ");
//         }
        
//         System.out.println();
//         while(!maxQueue.isEmpty()){
//            System.out.print(maxQueue.poll().get(0)+" "); 
//         }
        
        
        // System.out.println(maxQueue.peek().get(0));
        // System.out.println(minQueue.peek().get(0));
        int heapMax = maxQueue.poll().get(0);
        int heapMin = minQueue.poll().get(0);
        int ans =Integer.MIN_VALUE;
        if(minQueue.peek().get(1) != maxQueue.peek().get(1)){
            ans = Math.max(ans,Math.abs(maxQueue.peek().get(0)- minQueue.peek().get(0)));
        }else{
            // System.out.println(maxQueue.peek().get(0));
            // System.out.println(minQueue.peek().get(0));
            
            ans = Math.max(ans,Math.abs(heapMax- minQueue.peek().get(0)));
            ans = Math.max(ans,Math.abs(maxQueue.peek().get(0) - heapMin));
        }
        return ans;
        
        
        
    }
}