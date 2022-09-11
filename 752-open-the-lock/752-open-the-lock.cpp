class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int>mp;
        string s="0000";
        unordered_map<string,int>vis;   
        for(int i=0;i<deadends.size();i++)
        {
           mp[deadends[i]]=1; 
        }
        queue<string>q;
        q.push(s);
        int count=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                string a=q.front();
                q.pop();
                if(a==target)
                    return count;
                if(mp[a])
                    continue;
                for(int i=0;i<a.size();i++)
                {
                    int n=a[i]-'0';
                    int forw,back;
                    if(n==0)
                        back=9;
                    else
                        back=n-1;
                    if(n==9)
                        forw=0;
                    else
                        forw=n+1;
                    a[i]=back+'0';
                    if(vis[a]==0)
                    {
                        q.push(a);
                        vis[a]=1;
                    }
                    a[i]=forw+'0';
                    if(vis[a]==0)
                        {
                            q.push(a);
                            vis[a]=1;
                        }
                    a[i]=n+'0'; 
                }
                
            }
            count++;
        }
        return -1;
        
    }
};