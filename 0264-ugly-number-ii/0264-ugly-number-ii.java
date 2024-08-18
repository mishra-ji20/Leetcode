class Solution {
    public int nthUglyNumber(int n) {
        if(n==1){
            return 1;
        }
        PriorityQueue<ArrayList<Long>>uglyNumber = new  PriorityQueue<ArrayList<Long>>(new Comparator<ArrayList<Long>>(){
            public int compare(ArrayList<Long>first,ArrayList<Long> second){
                return first.get(0).compareTo(second.get(0));
            }
        });
        HashMap<Long, Integer> numberExist =  new HashMap<Long, Integer>();
        long [] factors = new long[] {(long)2,(long)3,(long)5};
        uglyNumber.add(new ArrayList(List.of((long)2,(long)1,(long)0)));
        int count=1 ;
        int ans =0;
        while(count<n){
            long currMin= uglyNumber.peek().get(0);
            long originalNumber = uglyNumber.peek().get(1);
            long index = uglyNumber.poll().get(2);
            if(numberExist.getOrDefault(currMin,0)==0){
                numberExist.put(currMin,1);
                uglyNumber.add(new ArrayList<Long>(List.of((long)(currMin*2),(long)currMin,(long)0)));
                count++;
            }
            if(index<2){
                index++;
                // System.out.println(typeof(index));
                long factor = factors[(int)index];
                long newNumber = (long)(originalNumber) * factor;
                uglyNumber.add(new ArrayList<Long>(List.of(newNumber,originalNumber,(long)(index))));
            }
            ans= (int)currMin;
            
        }
        return ans;
        
        
    }
}