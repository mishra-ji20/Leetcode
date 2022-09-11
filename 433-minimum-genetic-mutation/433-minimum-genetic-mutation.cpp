class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int>mp;
        for(int i=0;i<bank.size();i++)
        {
            mp[bank[i]]=1;
        }
        if(mp[end]==0)
            return -1;
        unordered_map<string,bool>vis;
        queue<string>q;
        q.push(start);
        int count=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                string a=q.front();
                if(a==end)
                    return count;
                for(int i=0;i<a.size();i++)
                {
                    char b=a[i];
                    a[i]='A';
                    if(mp[a]==1 && vis[a]==0){
                        q.push(a);
                        vis[a]=1;
                    }
                    a[i]='C';
                    if(mp[a]==1 && vis[a]==0){
                        q.push(a);
                        vis[a]=1;
                    }
                    a[i]='G';
                    if(mp[a]==1 && vis[a]==0){
                        q.push(a);
                        vis[a]=1;
                    }
                    a[i]='T';
                    if(mp[a]==1 && vis[a]==0){
                        q.push(a);
                        vis[a]=1;
                    }
                    a[i]=b; 
                }
                q.pop();
            }
            count++;
        }
        return -1;
        
    }
};