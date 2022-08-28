class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat){
        
        for(int i=1;i<mat[0].size();i++)
        {
            int a=0;
            int j=i;
            vector<int>ans;
            while(a<mat.size() && j<mat[0].size())
            {
                ans.push_back(mat[a][j]);
                a++;
                j++;
            }
            sort(ans.begin(),ans.end());
            int k=0;
            a=0;
            j=i;
            while(k<ans.size())
            {
                mat[a][j]=ans[k];
                a++;
                j++;
                k++;
            }
            
        }
        for(int i=0;i<mat.size();i++)
        {
            int a=i;
            int j=0;
            vector<int>ans;
            while(a<mat.size() && j<mat[0].size())
            {
                ans.push_back(mat[a][j]);
                a++;
                j++;
            }
            sort(ans.begin(),ans.end());
            int k=0;
            a=i;
            j=0;
            while(k<ans.size())
            {
                mat[a][j]=ans[k];
                a++;
                j++;
                k++;
            }
            
        }
        return mat;
         
    }
};