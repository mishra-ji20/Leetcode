class Solution {
public:
    
    int nearestExit(vector<vector<char>>& grid, vector<int>& enterance) {
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        q.push({enterance[0],enterance[1]});
        int count=0;
        int ans=INT_MAX;
        while(!q.empty())
        {
            int a=q.size();
            while(a--)
            {
                auto it=q.front();
                grid[it.first][it.second]='+';
                if(count!=0 && (it.first==0 || it.first==grid.size()-1 || it.second==0 || it.second==grid[0].size()-1))
                {
                    return count;
                }
                for(int k=0;k<dir.size();k++)
                {
                    int i=it.first+dir[k][0];
                    int j=it.second+dir[k][1];
                    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]=='.')
                    {
                        q.push({i,j});
                        grid[i][j]='+';
                    }
                }
                q.pop();
                
            }
            count++;
        }
        return -1;
        
    }
};