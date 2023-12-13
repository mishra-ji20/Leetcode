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

        return cnt+target-1;
        
    }
};