class Solution {
public:
    void mark_current_island(vector<vector<char>>& grid, int r, int c, int row, int col)
    {
        // Boundary conditions
        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != '1')
            return;
        
        // mark current island as visited
        grid[r][c] = '2';
        
        // mark all its neighbour visisted
        mark_current_island(grid, r-1, c, row, col); // up
        mark_current_island(grid, r+1, c, row, col); // down
        mark_current_island(grid, r, c-1, row, col); // left
        mark_current_island(grid, r, c+1, row, col); // right
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int numberOfIsland = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    mark_current_island(grid, i, j , row, col);
                    numberOfIsland++;
                }
            }
        }
        return numberOfIsland;
    }
};