class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
        vector<vector<int>>dp(triangle.size(),(vector<int>(triangle.size(),INT_MAX)));
        dp[0][0]=triangle[0][0];
        for(int i=0;i<triangle.size()-1;i++)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i+1][j]=min(dp[i+1][j],(dp[i][j]+triangle[i+1][j]));
                dp[i+1][j+1]=min(dp[i+1][j+1],(dp[i][j]+triangle[i+1][j+1])); 
               
            }
            
        }
         
        int ans=INT_MAX;
        for(int i=0;i<triangle.size();i++)
        {
            ans=ans<dp[triangle.size()-1][i]?ans:dp[triangle.size()-1][i];
        }
        return ans;
        
        
    }
};