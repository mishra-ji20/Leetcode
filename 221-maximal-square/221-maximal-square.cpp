class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>down(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>left(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
        {
            left[i][matrix[0].size()-1]=matrix[i][matrix[0].size()-1]-'0';
            for(int j=matrix[0].size()-2;j>=0;j--)
            {
                if(matrix[i][j]!='0')
                    left[i][j]=matrix[i][j]-'0'+left[i][j+1];
            }
        }
        // for(int i=0;i<dp.size();i++)
        // {
        //     for(int j=0;j<dp[0].size();j++)
        //         cout<<left[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int j=0;j<matrix[0].size();j++)
        {
            down[matrix.size()-1][j]=matrix[matrix.size()-1][j]-'0';
            for(int i=matrix.size()-2;i>=0;i--)
            {
                if(matrix[i][j]!='0')
                    down[i][j]=matrix[i][j]-'0'+down[i+1][j];
            }
        }
//         for(int i=0;i<dp.size();i++)
//         {
//             for(int j=0;j<dp[0].size();j++)
//                 cout<<down[i][j]<<" ";
//             cout<<endl;
//         }
//         cout<<endl;
        
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            dp[i][matrix[0].size()-1]=(left[i][matrix[0].size()-1] | down[i][matrix[0].size()-1])?1:0;
            ans=max(ans,dp[i][matrix[0].size()-1]);
        }
         for(int j=0;j<matrix[0].size();j++){
            dp[matrix.size()-1][j]=(left[matrix.size()-1][j] | down[matrix.size()-1][j])?1:0;
             ans=max(ans,dp[matrix.size()-1][j]);
         }
        for(int i=matrix.size()-2;i>=0;i--)
        {
            for(int j=matrix[0].size()-2;j>=0;j--)
            {
                if(min(left[i][j],down[i][j])>dp[i+1][j+1])
                    dp[i][j]=dp[i+1][j+1]+1;
                else
                    dp[i][j]=min(left[i][j],down[i][j]);
                ans=max(ans,dp[i][j]*dp[i][j]);
            }
        }
        // for(int i=0;i<dp.size();i++)
        // {
        //     for(int j=0;j<dp[0].size();j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        return ans;
        
    }
};