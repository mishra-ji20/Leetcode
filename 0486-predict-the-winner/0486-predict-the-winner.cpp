class Solution {
public:
    bool func(int i,int j,vector<long long> &sum,vector<int> &nums,bool flag)
    {
        // cout<<i<<" "<<j<<" "<<flag<<endl;
        if(i>j)
        {
            // cout<<sum[0]<<" "<<sum[1]<<endl;
            return sum[0]>=sum[1];
        }
        sum[flag]+=nums[i];
       bool a= func(i+1,j,sum,nums,(!flag));
        sum[flag]-=nums[i];
        sum[flag]+=nums[j];
       bool b= func(i,j-1,sum,nums,(!flag));
        sum[flag]-=nums[j];
        if(flag==1)
        {
           return a&b;  
        }
        return a|b;
        
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<long long>sum(2,0);
        return func(0,nums.size()-1,sum,nums,0);
        
        
    }
};