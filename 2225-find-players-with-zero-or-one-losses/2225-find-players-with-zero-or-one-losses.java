class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        HashMap<Integer,Integer> mp=new HashMap<Integer,Integer>();
        HashMap<Integer,Integer> wmp=new HashMap<Integer,Integer>();
        for(int i=0;i<matches.length;i++){
            mp.put(matches[i][1],mp.getOrDefault(matches[i][1],0)+1);
            wmp.put(matches[i][0],1);
        }
        List<Integer>winner=new ArrayList<Integer>();
        List<Integer>loser=new ArrayList<Integer>();
        mp.forEach((key,value)->{
            if(value==1){
                loser.add(key);
            }
            wmp.put(key,0);
        });
        wmp.forEach((key,value)->{
            if(value==1){
                winner.add(key);
            }
        });
        Collections.sort(winner);
        Collections.sort(loser);
        List<List<Integer>>arr=new ArrayList<>();
        arr.add(winner);
        arr.add(loser);
        return arr;
        
    }
}