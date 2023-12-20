class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>miDq;
        deque<int>maDq;
        int ans=0;
        int i=0,j=1;
        miDq.push_front(nums[0]);
        maDq.push_front(nums[0]);
        while(j<=nums.size()){
            // cout<<maDq.size()<<" "<<miDq.size()<<endl;
            if(!maDq.empty() && !miDq.empty() && maDq.back()-miDq.back()>limit){
                int ma=maDq.back();
                int mi=miDq.back();
                // cout<<ma<<" "<<mi<<endl;
                if(nums[i]==ma){
                    maDq.pop_back();
                }
                 if(nums[i]==mi){
                    miDq.pop_back();
                }
                i++;
            }else{
                ans=max(ans,j-i);
                // cout<<j<<" "<<i<<endl;
                if(j<nums.size()){
                    while(!maDq.empty() && maDq.front()<nums[j]){
                        maDq.pop_front();
                    }
                    while(!miDq.empty() && miDq.front()>nums[j]){
                        miDq.pop_front();
                    }
                    maDq.push_front(nums[j]);
                    miDq.push_front(nums[j]);
                    // cout<<maDq.back()<<" "<<miDq.back()<<endl;
                }
                j++;
                
            }
            
        }
        return ans;
        
    }
};