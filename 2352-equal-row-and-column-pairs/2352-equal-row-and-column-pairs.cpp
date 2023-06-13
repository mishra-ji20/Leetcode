class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        for(int i=0;i<grid.size();i++)
        {
            vector<int>arr;
            for(int j=0;j<grid[0].size();j++)
            {
                arr.push_back(grid[i][j]);   
            }
            mp[arr]++;
            
        }
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            vector<int>arr;
            for(int j=0;j<grid[0].size();j++)
            {
                arr.push_back(grid[j][i]);
            }
          
                count+=mp[arr];
        }
        return count;  
    }
};