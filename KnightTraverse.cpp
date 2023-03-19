 bool validate(int r,int c,int m, int n){
        if(r<m && c<n && r>=0 && c>=0)
            return true;
        return false;
        
    } 
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<vector<bool>>grid(grid.size(),vector<bool>(grid.size(),0));
        vector<pair<int,int>>arr;
        arr.push_back({2,1});
        arr.push_back({2,-1});
        arr.push_back({-2,-1});
        arr.push_back({-2,1});
        arr.push_back({1,2});
        arr.push_back({1,-2});
        arr.push_back({-1,-2});
        arr.push_back({-1,2});
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        int cnt=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto a=q.front();
                q.pop();
                for(int i=0;i<arr.size();i++)
                {
                    if(validate(a.first+arr[i].first,a.second+arr[i].second,grid.size(),grid.size()) && vis[a.first+arr[i].first][a.second+arr[i].second]==0)
                    {
                        q.push({a.first+arr[i].first,a.second+arr[i].second})
                    }
                }
            }
            cnt++;
        }
        
        
    }
};
