class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        vector<priority_queue<int>>q(grid.size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                q[i].push(grid[i][j]);
            }
        }
        int sum=0;
        int x=q[0].size();
        for(int i=0;i<x;i++){
            int ma=0;
            // cout<<i<<' ';
            for(int j=0;j<q.size();j++){
                ma=max(q[j].top(),ma);
                q[j].pop();
            }
            // cout<<ma<<" ";
            sum+=ma;
        }
        return sum;
        
    }
};