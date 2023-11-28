class Solution {
public:
    int numberOfWays(string corridor) {
        vector<vector<int>>seats;
        int mod=1e9+7;
        int seatCount=0;
        int cnt=0;
        // for(int i=0;i<)
        for(int i=0;i<corridor.size();i++) {
            vector<int>arr;
            if(corridor[i]=='S') {
                seatCount++;
                arr.push_back(i);
                i++;
                while(i<corridor.size() && (seatCount&1)){
                    if(corridor[i]=='S') {
                        seatCount++;
                        arr.push_back(i);
                        break;
                    }
                    i++;
                }
            }
            // cout<<arr.size()<<endl;
            if(arr.size()!=0){
                // cout<<arr[0]<<" "<<arr[1]<<endl;
                seats.push_back(arr);
            }
            
        }
        // cout<<seatCount<<" ";
        if(seatCount==0 || (seatCount&1)){

            return 0;
        }
        vector<long>dp(seats.size(),0);
        dp[0]=1;
        
        for(int i=1;i<seats.size();i++){
            dp[i]=(dp[i-1]*((long)(seats[i][0]-seats[i-1][1]))%mod)%mod;
        }
        return dp[dp.size()-1];
        
        
    }
};