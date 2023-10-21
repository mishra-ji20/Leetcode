class Solution {
public:

    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<long,long>>q;
        long ans=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            
            if(q.size()!=0 && i-q.back().second>k) {
                // cout<<q.empty()<<" ";
                q.pop_back();
            }
            int x=nums[i];
            if(q.size()!=0) {
                // cout<<nums[i]+q.back().first<<" ";
                x=x>nums[i]+q.back().first?x:nums[i]+q.back().first;
            }
            while(q.size()!=0 && q.front().first<x){
                q.pop_front();
            }
           
            ans=ans>x?ans:x;
            q.push_front({x,i});
            // cout<<q.size()<<" ";
            // cout<<q.front().first<<"\tAks";
            // cout<<x<<" ";
        }
        return ans;
        
    }
};