class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt=0;
        while(target!=1 && maxDoubles){
            if(target&1){
                target--;
            }else{
                target=target/2;
                maxDoubles--;
            }
            cnt++;
        }
        if(target==1){
            return cnt;
        }else{
            return cnt+target-1;
        }
        
        
        
    }
};