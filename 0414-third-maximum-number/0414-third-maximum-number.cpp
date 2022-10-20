class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==0)
            {
                if(q.size()<3)
                    q.push(nums[i]);
                else if(nums[i]>q.top())
                {
                    q.push(nums[i]);
                    q.pop();
                }
            }
            mp[nums[i]]=1;
                
        }
        if(q.size()>=3)
        return q.top();
        cout<<0;
        int ans;
        while(!q.empty())
        {
            ans=q.top();
            q.pop();
        }
        return ans;
    }

};