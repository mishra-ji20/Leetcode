class Solution {
public:
    void dfs(vector<string>graph[],string s,vector<int>vis[],int count,int &tot,vector<string>ans,vector<string> &res,unordered_map<string,int> &mp,int &flag) {
        ans.push_back(s);
        
        count++;
        // cout<<s<<" "<<count<<"\t";
        if(count==tot) {
            // cout<<count<<' ';
            res=ans;
            flag=1;
        }
        if(flag) return;
        
        for(int j=0;j<graph[mp[s]].size();j++) {
            if(vis[mp[s]][j]!=1) {
                vis[mp[s]][j]=1;
                dfs(graph,graph[mp[s]][j],vis,count,tot,ans,res,mp,flag);
                vis[mp[s]][j]=0;
            }
            if(flag==1)
                return;
                
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,int>mp;
        int counter=1;
        for(int i=0;i<tickets.size();i++) {
            if(mp[tickets[i][0]]==0) {
                mp[tickets[i][0]]=counter;
                counter++;
            }
            if(mp[tickets[i][1]]==0) {
                mp[tickets[i][1]]=counter;
                counter++;
            }
            
        }
        vector<string>graph[counter];
        vector<int>vis[counter];
        for(int i=0;i<tickets.size();i++) {
            graph[mp[tickets[i][0]]].push_back(tickets[i][1]);
            vis[mp[tickets[i][0]]].push_back(0);
        }
        for(int i=0;i<counter;i++) {
            sort(graph[i].begin(),graph[i].end());
        }
        vector<string>ans;
        vector<string>res;
        string s="JFK";
        vector<int>iterator(counter,0);
        int tot=tickets.size()+1;
        int flag=0;
        dfs(graph,s,vis,0,tot,ans,res,mp,flag);
        // cout<<endl;
        return res;
        
    }
};