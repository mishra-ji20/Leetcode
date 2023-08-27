class Solution {
    public boolean canCross(int[] stones) {
        HashMap<Integer,HashMap<Integer,Integer>>mp=new HashMap<Integer,HashMap<Integer,Integer>>();
        if(stones[0]!=0 || 1!= stones[1])
            return false;
        
        for(int i=1;i<stones.length;i++)
        {
            mp.put(stones[i],new HashMap<Integer,Integer>());
        }
        mp.get(1).put(1,1);
        for(int i=1;i<stones.length;i++)
        {
            for(Integer jump: mp.get(stones[i]).keySet())
            {
                // System.out.print(jump+" ");
                if(jump!=1 && mp.get(stones[i]+jump-1)!=null)
                {
                    mp.get(stones[i]+jump-1).put(jump-1,1);
                    
                }
                if(mp.get(stones[i]+jump)!=null)
                {
                    mp.get(stones[i]+jump).put(jump,1);
                    
                }
                if(mp.get(stones[i]+jump+1)!=null)
                {
                    mp.get(stones[i]+jump+1).put(jump+1,1); 
                }
            }
            // System.out.println();
        }
        if(mp.get(stones[stones.length-1]).size()>0)
            return true;
        return false;
        
    }
}
