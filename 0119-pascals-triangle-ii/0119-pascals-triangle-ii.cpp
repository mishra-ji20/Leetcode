class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>dp(1,0);
        dp[0]=1;
        for(int i=0;i<=rowIndex;i++) {
            vector<int>temp(i+1,0);
            temp[0]=1;
            for(int j=1;j<i;j++) {
                temp[j]=dp[j-1]+dp[j];
            }
            temp[i]=1;
            dp=temp;
            
        }
        return dp;
        
    }
};