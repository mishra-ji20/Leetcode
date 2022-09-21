class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
                sum=sum+nums[i];
        }
        for(int i=0;i<queries.size();i++)
        {
            if((abs(nums[queries[i][1]])%2==0 && abs(queries[i][0])%2==0))
            {
                sum=sum+queries[i][0];
                nums[queries[i][1]]=nums[queries[i][1]]+queries[i][0];
            }
            else if((abs(nums[queries[i][1]])%2 && abs(queries[i][0])%2))
            {
                sum=sum+nums[queries[i][1]]+queries[i][0];
                nums[queries[i][1]]=nums[queries[i][1]]+queries[i][0];
            }
            else if((abs(nums[queries[i][1]])%2==0 && abs(queries[i][0])%2))
            {
                sum=sum-(nums[queries[i][1]]);
                nums[queries[i][1]]=nums[queries[i][1]]+queries[i][0];
            }
            else
                nums[queries[i][1]]=nums[queries[i][1]]+queries[i][0];
            ans.push_back(sum);
                
            
            
        }
        return ans;
        
    }
};