class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>res(grid.size(),vector<int>(grid.size(),INT_MAX));
        if(grid[0][0]==1)
            return -1;
        res[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty())
        {
            
            pair<int,int>p=q.front();
            q.pop();
            int i=p.first;
            int j =p.second;
             if(i<grid.size()-1 && res[i][j]+1<res[i+1][j] && grid[i+1][j]==0){
                 res[i+1][j]=res[i][j]+1;
                 q.push({i+1,j});
            }
            if(j<grid.size()-1 && res[i][j]+1<res[i][j+1] && grid[i][j+1]==0){
           res[i][j+1]=res[i][j]+1;
                q.push({i,j+1});
        }
        if(i<grid.size()-1 && j<grid.size()-1 && res[i][j]+1<res[i+1][j+1] && grid[i+1][j+1]==0){
           res[i+1][j+1]=res[i][j]+1;
                q.push({i+1,j+1});
        }
        if(i>0 && res[i][j]+1<res[i-1][j] && grid[i-1][j]==0 ){
           res[i-1][j]=res[i][j]+1;
                q.push({i-1,j});
        }
        if(j>0 && res[i][j]+1<res[i][j-1] && grid[i][j-1]==0 ){
           res[i][j-1]=res[i][j]+1;
                q.push({i,j-1});
            }
        if(i>0 && j>0 && res[i][j]+1<res[i-1][j-1] && grid[i-1][j-1]==0 ){
           res[i-1][j-1]=res[i][j]+1;
                q.push({i-1,j-1});
        }
         if(i>0 && j<grid.size()-1 && res[i][j]+1<res[i-1][j+1] && grid[i-1][j+1]==0 ){
            res[i-1][j+1]=res[i][j]+1;
                q.push({i-1,j+1});
        }
         if(i<grid.size()-1 && j>0 &&res[i][j]+1<res[i+1][j-1] && grid[i+1][j-1]==0 ){
           res[i+1][j-1]=res[i][j]+1;
                q.push({i+1,j-1});
        }
            
        }
        return res[grid.size()-1][grid.size()-1]==INT_MAX?-1: res[grid.size()-1][grid.size()-1];
        
    }
};