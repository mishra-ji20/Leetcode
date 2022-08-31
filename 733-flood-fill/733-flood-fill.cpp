class Solution {
public:
    void dfs(vector<vector<int>>&image, vector<vector<int>>& vis,int sr,int sc,int color,int org)
    {
        if(sr>=image.size() || sc>=image[0].size() || sr<0 || sc<0 ||vis[sr][sc] || image[sr][sc]!=org)
            return;
        vis[sr][sc]=1;
        image[sr][sc]=color;
        dfs(image,vis,sr+1,sc,color,org);
        dfs(image,vis,sr-1,sc,color,org);
        dfs(image,vis,sr,sc+1,color,org);
        dfs(image,vis,sr,sc-1,color,org);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        dfs(image,vis,sr,sc,color,image[sr][sc]);
        return image;
        
    }
};