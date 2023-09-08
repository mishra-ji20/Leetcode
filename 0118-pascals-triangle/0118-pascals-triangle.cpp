class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>res;
        res.push_back(1);
        ans.push_back(res);
        for(int i=0;i<numRows-1;i++)
        {
            vector<int>temp(ans[i].size()+1,0);
            for(int j=0;j<ans[i].size();j++ )
            {
                temp[j]=temp[j]+ans[i][j];
                temp[j+1]=temp[j+1]+ans[i][j];
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};