class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long long int,long long int>>mp(nums.size());
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
          for(int j=i-1;j>=0;j--)
          {
              long long int d=(long long)(nums[i])-(long long)(nums[j]);
              mp[i][d]=mp[i][d]+mp[j][d]+1;
             sum=sum+mp[j][d];
          }
            
            
        }
        return sum;
        
    }
};