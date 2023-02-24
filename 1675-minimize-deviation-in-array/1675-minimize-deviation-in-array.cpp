
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
      priority_queue<long long>q;
        long long mi=LLONG_MAX;
        long long ma=LLONG_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2)
                nums[i]=nums[i]*2;
            mi=mi<nums[i]?mi:nums[i];
            q.push(nums[i]);
        }
        long long ans=q.top()-mi;
        while(q.top()%2==0)
        {
            long a=q.top();
            q.pop();
            a=a/(long)2;
            q.push(a);
            mi=mi<a?mi:a;
            ma=q.top();
            ans=ans<ma-mi?ans:ma-mi;
            // cout<<ans<<" ";
        }
        return ans;
        
        
    }
};