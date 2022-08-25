class Solution {
public:
    void sol(vector<bool>vis,vector<int>res,vector<vector<int>>&ans,vector<int>nums)
    {
        
           
            for(int j=0;j<nums.size();j++)
            {
                if(vis[j]!=1){
                    res.push_back(nums[j]);
                    vis[j]=1;
                     sol(vis,res,ans,nums); 
                    vis[j]=0;
                    res.pop_back();
                }
            }
            if(res.size()==nums.size())
                ans.push_back(res);
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>vis(nums.size(),0);
        vector<int>res;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(nums[i]);
            vis[i]=1;
            sol(vis,res,ans,nums);
            vis[i]=0;
            res.pop_back();
        }
        return ans;
        
        
    }
};