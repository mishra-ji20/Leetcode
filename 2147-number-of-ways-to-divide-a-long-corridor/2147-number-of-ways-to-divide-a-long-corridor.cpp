class Solution {
public:
    int numberOfWays(string corridor) {
        vector<vector<int>>seats;
        int mod=1e9+7;
        int seatCount=0;
        long cnt=1;
        long prev=1;
        for(int i=0;i<corridor.size();i++) {
            if(corridor[i]=='S'){
                seatCount++;
                if((seatCount&1)==0){
                    prev=(prev*(cnt))%mod;
                    cnt=0;
                }
            }
            if(seatCount!=0 && (seatCount&1)==0){
                cnt++;
            }
        }
        // cout<<seatCount<<" ";
        if(seatCount==0 || (seatCount&1)){

            return 0;
        }
        return prev;
        
        
        
    }
};