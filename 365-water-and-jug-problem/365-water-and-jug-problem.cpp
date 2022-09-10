class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        if(j1+j2<t)
            return 0;
        if(t==j1 || t==j2)
            return 1;
        int ma=max(j1,j2);
        vector<bool> vis(ma+1,0);
        queue<int>q;
        vis[j1]=1;
        vis[j2]=1;
        q.push(abs(j1-j2));
        vis[abs(j1-j2)]=1;
        while(!q.empty())
        {
            int a=q.front();
            vis[a]=1;
         // cout<<a<<" ";
            if(a==t)
                return 1;
            if( vis[abs(j1-a)]==0)q.push(abs(j1-a));
            if( vis[abs(j2-a)]==0)q.push(abs(j2-a));
            q.pop(); 
        }
        if(t>ma)
            return (vis[t-j1]||vis[t-j2]);
        else
            return vis[t];
            
        
    }
};