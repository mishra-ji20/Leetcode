class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>res(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int j=0;j<matrix[0].size();j++){
            for(int i=matrix.size()-1;i>=0;i--){
                if(i<matrix.size()-1 && matrix[i][j]==1){
                    res[i][j]=res[i+1][j]+1;
                }
                if(i==matrix.size()-1){
                    res[i][j]=matrix[i][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            sort(res[i].rbegin(),res[i].rend());
            for(int j=0;j<matrix[i].size();j++){
                // cout<<res[i][j]<<" ";
                ans=max(ans,(res[i][j]*(j+1)));
            }
            // cout<<endl;
        }
        return ans;
        
    }
};