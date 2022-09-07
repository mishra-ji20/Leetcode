class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>v(isConnected.size(),0);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(v[i]==1)
                continue;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int a=q.front();
                v[a]=1;
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[a][j]==1 && v[j]==0){
                    v[j]==1;
                    q.push(j); 
                }
            }
                q.pop();
                
            }
           count++;
        }
        return count;
        
    }
};