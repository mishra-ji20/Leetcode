class Solution {
public:
    bool comp(string &s1,string &s2){
        int flag=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
                flag++;
        }
        // cout<<flag<<" ";
        return flag==1;
        
    }
   int ladderLength(string begin, string end, vector<string>& list) {
       unordered_map<string,int>mp;
       mp[begin]=0;
       for(int i=0;i<list.size();i++)
       {
           if(list[i]!=begin)
           mp[list[i]]=i+1;
       }
       if(mp[end]==0)
           return 0;
       vector<int>graph[list.size()+1];
       for(int i=0;i<list.size();i++)
       {
           if(comp(begin,list[i]))
           {
                graph[mp[begin]].push_back(mp[list[i]]);
                graph[mp[list[i]]].push_back(mp[begin]);
           }
               
       }
       for(int i=0;i<list.size();i++)
       {
           for(int j=i+1;j<list.size();j++)
           {
               if(comp(list[i],list[j]))
               {
                   graph[mp[list[i]]].push_back(mp[list[j]]);
                   graph[mp[list[j]]].push_back(mp[list[i]]);
                   
               }
               
           }
           // cout<<endl;
       }
//        for(int i=0;i<=list.size();i++)
//        {
//            for(int j=0;j<graph[i].size();j++)
//                cout<<graph[i][j]<<" ";
//            cout<<endl;
//        }
       
       queue<int>q;
       q.push(0);
       int count=0;
       vector<bool>vis(list.size()+1,0);
       vis[0]=1;
       while(!q.empty())
       {
           int s=q.size();
           while(s--)
           {
               int a=q.front();
               if(a==mp[end])
                   return count+1;
               for(int i=0;i<graph[a].size();i++)
               {
                   if(vis[graph[a][i]]==0){
                   q.push(graph[a][i]);
                    vis[graph[a][i]]=1;
                   }
                       
               }
               q.pop();
           }
           count++;
            
       }
       return 0;
       
       
    }
};