class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_map<int,int>>mp;
        int x=0;
        int y=0;
        mp[x][y]=1;
        for(int i=0;i<path.size();i++){
            if(path[i]=='N'){
                y++;
            }else if(path[i]=='E'){
                x++;
            }else if(path[i]=='S'){
                y--;
            }else{
                x--;
            }
            if(mp[x][y]){
                return true;
            }
            mp[x][y]=1;
        }
        return false;
        
    }
};