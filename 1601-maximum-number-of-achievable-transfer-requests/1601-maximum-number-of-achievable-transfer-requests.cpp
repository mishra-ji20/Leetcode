class Solution {
public:
    void approve(vector<int>&space,vector<vector<int>> &request,int sum,int &res,int i,int ans)
    {
        if(i>=request.size() )
        {
            if(sum==0){
            res=max(ans,res);
             }
            return;
        }
        approve(space,request,sum,res,i+1,ans);
        
        ans++;
        if(space[request[i][1]]==0)
        {
            sum++;
        }
        space[request[i][1]]++;
        space[request[i][0]]--;
        if(space[request[i][0]]==0)
            sum--;
        approve(space,request,sum,res,i+1,ans);
        space[request[i][1]]--;
        space[request[i][0]]++;
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>space(n,0);
        int res=0;
        vector<int>path;
        approve(space,requests,0,res,0,0);
        return res;
        
    }
};