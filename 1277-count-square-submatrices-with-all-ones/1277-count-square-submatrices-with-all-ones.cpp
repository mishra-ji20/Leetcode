class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>rowDp(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>columnDp(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix.size();i++){
            int cnt=0;
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]){
                    cnt++;
                }else{
                    cnt=0;
                }
                rowDp[i][j]=cnt;
                // cout<<i<<" "<<j<<" "<<rowDp[i][j]<<"      ";
            }
            // cout<<endl;
        }
        for(int j=0;j<matrix[0].size();j++){
            int cnt=0;
            for(int i=0;i<matrix.size();i++){
                if(matrix[i][j]){
                    cnt++;
                }else{
                    cnt=0;
                }
                
                columnDp[i][j]=cnt;
                // cout<<i<<" "<<j<<" "<<columnDp[i][j]<<"      ";
            }
            // cout<<endl;
        }
        int sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int x;
                if(i-1>=0 && j-1>=0){
                    x=dp[i-1][j-1];
                }
                else
                    x=0;
                if(matrix[i][j]!=0){
                    int y=min(rowDp[i][j],columnDp[i][j]);
                    if(x==0){
                        dp[i][j]=1; 
                    }else{
                        dp[i][j]=min(x+1,y);
                    }
                    sum+=(dp[i][j]);
                    // cout<<"hey";
                }
                // cout<<dp[i][j]<<' ';
                
            }
            // cout<<endl;
        }
        return sum;
        
        
    }
};