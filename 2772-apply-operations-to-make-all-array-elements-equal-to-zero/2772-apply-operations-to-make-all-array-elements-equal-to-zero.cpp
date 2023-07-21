class Solution {
public:
    bool check(vector<int> &nums,int k)
    {
        if(nums.size()==1 || k==1)
            return 1;
        queue<int>q;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums.size()-1==i)
            {
                if(sum!=nums[i])
                    return 0;
                
            }
            if(sum>nums[i])
                return 0;
            else
                nums[i]-=sum;
            q.push(nums[i]);
            sum+=nums[i];
            if(q.size()==k)
            {
                sum-=q.front();
                q.pop();
            }
        }
        return 1;
    }
    bool checkArray(vector<int>& nums, int k) {
       int a=check(nums,k);
       // reverse(nums.begin(),nums.end());
       //  int b=check(nums,k);
        return a;
        
        
        
    }
};