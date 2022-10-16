class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>res;
        for(int i=1;i<nums.size();i++)
        {
            res.push_back(nums[i]-nums[i-1]);
        }
        int count=0;
        int sum=0;
        for(int i=0;i<res.size();)
        { int j=i+1;
         count=1;
            while(j<res.size() && (res[i])==(res[j]))
            {
                count++;
                j++;
            }
         count=count-1;
         sum=sum+((count*(count+1)/2));
         i=j;
        }
        return sum;
        
    }
};