class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
    vector<vector<int>> m(rs.size(), vector<int>(cs.size()));
    for (int x = 0; x < rs.size(); ++x){
        for (int y = 0; y < cs.size() && rs[x] > 0; ++y) {
            // cout<<x<<" "<<y<<"  ";
            m[x][y] = min(rs[x], cs[y]);
            rs[x] -= m[x][y];
            cs[y] -= m[x][y];
        }
        // cout<<endl;
    }
    return m;
        
    }
};