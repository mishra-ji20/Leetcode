class Solution {
public:
    int minimumJumps(vector<int>& forb, int a, int b, int x) {
        if(x==0)
            return 0;
        unordered_map<int,int>vis1;
        unordered_map<int,int>vis2;
        for(int i=0;i<forb.size();i++)
        {
            vis1[forb[i]]=1;
            vis2[forb[i]]=1;
        }
        queue<pair<int,int>>q;
        q.push({0,1});
        vis1[0]=1;
        vis2[0]=1;
        int count=1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto i=q.front();
                int dir1=i.first+a,dir2=i.first-b;
                if(vis1[dir1]==0 && dir1<=max(x+a+b,5000)){
                    // cout<<dir1<<" ";
                    if(dir1==x)
                        return count;
                    q.push({dir1,0});
                    vis1[dir1]=1;
                }
                if(i.second==0 && dir2>0 && vis2[dir2]==0){
                    // cout<<dir2<<" ";
                    if(dir2==x)
                        return count;
                    q.push({dir2,1});
                    vis2[dir2]=1;
                }
                q.pop();
                
            }
            count++;
        }
       
        return -1;
    }
};