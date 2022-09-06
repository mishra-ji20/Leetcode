class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool>vis(rooms.size(),0);
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int a=q.front();
            vis[a]=1;
            int i=0;
            while(i<rooms[a].size()){
                if(vis[rooms[a][i]]==0)
                    q.push(rooms[a][i]);
                i++;
            }
            q.pop();
        }
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0)
                return false;
        }
        return true;
        
        
    }
};