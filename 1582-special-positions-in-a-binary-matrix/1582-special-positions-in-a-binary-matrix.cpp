class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int,int>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    mp[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<mat.size();i++){
            int sum=0,k=-1;
            for(int j=0;j<mat[i].size();j++){
                
                if(mat[i][j]==1){
                    sum++;
                    k=j;
                }
            }
            if(sum==1){
                if(mp[k]==1){
                    ans++;
                }
            }
        }
       
        return ans;
        
    }
};