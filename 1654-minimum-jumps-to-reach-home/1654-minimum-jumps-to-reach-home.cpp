class Solution {
public:
    int minimumJumps(vector<int>& forb, int a, int b, int x) {
        map<pair<int,int>,int>vis1;
        for(int i=0;i<forb.size();i++)
        {
            vis1[{forb[i],0}]=1;
            vis1[{forb[i],1}]=1;
        }
        queue<pair<int,int>>q;
        q.push({0,1});
        int count=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto i=q.front();
                q.pop();
                if(i.first==x)
                    return count;
                if(vis1[i])
                    continue;
                vis1[i]=1;
                int dir1=i.first+a,dir2=i.first-b;
                if(dir1<=max(x+a+b,5000)){
                    q.push({dir1,0});
                }
                if(i.second==0 && dir2>0){
                    q.push({dir2,1});
                } 
            }
            count++;
        }
       
        return -1;
    }
};