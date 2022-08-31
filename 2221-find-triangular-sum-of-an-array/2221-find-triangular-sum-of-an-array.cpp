class Solution {
public:
    int triangularSum(vector<int>& nums) {
       vector<vector<int>>arr;
        arr.push_back(nums);
        for(int i=0;i<nums.size()-1;i++)
        {
            vector<int>res;
            for(int j=0;j<arr[i].size()-1;j++)
            {
                res.push_back((arr[i][j+1]+arr[i][j])%10);
            }
            arr.push_back(res);
        }
        return arr[arr.size()-1][0];
      
    }
};