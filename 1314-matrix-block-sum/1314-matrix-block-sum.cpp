class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>dp(mat.size(),vector<int>(mat[0].size()+1,0));
        int m=mat.size()-1;
        int n=mat[0].size()-1;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=1;j<=mat[0].size();j++)
            {
                dp[i][j]=dp[i][j-1]+mat[i][j-1];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        vector<vector<int>>sol(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                int a=max(0,j-k);
                int b=min(n,j+k);
                int c=max(0,i-k);
                int d=min(m,i+k);
                while(c<=d)
                {
                    sol[i][j]+=-dp[c][a]+dp[c][b+1];
                    c++;
                }
            }
        }
        return sol;
    }
};