class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& arr) {
        vector<vector<int>>ans;
        for(int i=0;i<arr[0].size();i++)
        {
            vector<int>res;
            for(int j=0;j<arr.size();j++)
            {
                res.push_back(arr[j][i]);
               
            }
            ans.push_back(res);
        }
        return ans;
        
    }
};