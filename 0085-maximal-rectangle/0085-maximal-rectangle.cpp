class Solution {
public:
    int maximalRectangle(vector<vector<char>>& arr) {
        vector<vector<int>>matrix(arr.size(),vector<int>(arr[0].size(),0));
        for(int i=0;i<arr[0].size();i++){
            matrix[0][i]=arr[0][i]-'0';
        }
        for(int j=0;j<arr[0].size();j++){
            for(int i=1;i<arr.size();i++){
                if(arr[i][j]=='1'){
                    matrix[i][j]=matrix[i-1][j]+1;
                }
               // cout<<i<<' '<<j<<" "<<matrix[i][j]<<"          ";
            }
            // cout<<endl;
        }
        
        vector<vector<int>>left(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>right(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            stack<int>st;
            for(int j=0;j<matrix[i].size();j++){
                while(!st.empty() && matrix[i][st.top()]>=matrix[i][j]){
                     st.pop();
                }
                if(st.empty()){
                    left[i][j]=-1;
                }else{
                    left[i][j]=st.top();
                }
                st.push(j);
            }
        }
        for(int i=0;i<matrix.size();i++){
            stack<int>st;
            for(int j=matrix[i].size()-1;j>=0;j--){
                while(!st.empty() && matrix[i][st.top()]>=matrix[i][j]){
                     st.pop();
                }
                if(st.empty()){
                    right[i][j]=matrix[i].size();
                }else{
                    right[i][j]=st.top();
                }
                st.push(j);
            }
        }
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                // cout<<right[i][j]<<" "<<left[i][j]<<" "<<matrix[i][j]<<"           ";
                int x=(((right[i][j]-left[i][j])-1)*(matrix[i][j]));
                ans=max(ans,x);
            }
            // cout<<endl;
        }
        return ans;
        
    }
};