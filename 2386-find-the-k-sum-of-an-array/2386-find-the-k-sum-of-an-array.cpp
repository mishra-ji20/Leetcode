class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum1=0;
        long long sum2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                sum1=sum1+nums[i];
                else
                nums[i]=abs(nums[i]);
            
        }
        sort(nums.begin(),nums.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({nums[0],0});
        vector<long long int>arr;
        while(!q.empty() && arr.size()<k)
        {
            auto a=q.top();
            arr.push_back(a.first);
            // cout<<a.first<<" "<<a.second<<" ";
            if(a.second<nums.size()-1)
            {
                q.push({a.first+nums[a.second+1],a.second+1});
                q.push({nums[a.second+1]+(a.first-nums[a.second]),a.second+1});
            }
            q.pop();
        }
        vector<long long int>ans;
        ans.push_back(sum1);
        for(int i=0;i<arr.size();i++)
            ans.push_back(sum1-arr[i]);
        return ans[k-1];
    }
};
