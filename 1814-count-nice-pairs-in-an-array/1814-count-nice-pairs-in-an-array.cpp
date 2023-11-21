class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<nums.size();i++){
            int orgNum=nums[i];
            int revNum=0;
            while(orgNum>0){
                revNum=(revNum*10)+(orgNum%10);
                orgNum/=10;
            }
            // cout<<nums[i]-revNum<<" ";
            ans=((ans%mod)+(mp[nums[i]-revNum]%mod))%mod;
            mp[nums[i]-revNum]++;
                
        }

        return ans;
        
    }
};