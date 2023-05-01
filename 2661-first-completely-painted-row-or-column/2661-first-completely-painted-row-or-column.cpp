class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>mpr;
        unordered_map<int,int>mpc;
        unordered_map<int,int>row_count;
        unordered_map<int,int>c_count;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                mpr[mat[i][j]]=i;
                mpc[mat[i][j]]=j;
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            // cout<<mpr[arr[i]]<<" ";
            // cout<<mpc[arr[i]]<<endl;
            row_count[mpr[arr[i]]]++;
            c_count[mpc[arr[i]]]++;
            if(row_count[mpr[arr[i]]]==mat[0].size() || c_count[mpc[arr[i]]]==mat.size())
                return  i;   
        }
        return 0;
            
    }
};