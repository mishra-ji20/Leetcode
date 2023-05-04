class Solution {
public:
    void bfsShortestPathApproach(vector<vector<long>> &graph,vector<long>& vis,int src)
    {
        queue<pair<long,long>>q;
        q.push({src,0});
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto a=q.front();
                q.pop();
                // cout<<a.first<<" ";
                
                    for(int i=1;i<graph[a.first].size();i++)
                    {
                    
                        if(graph[a.first][i]!=LONG_MAX && vis[i]>graph[a.first][i]+a.second)
                        {
                            q.push({i,graph[a.first][i]+a.second});
                            vis[i]=graph[a.first][i]+a.second;
                        }
                    }
                }
            }
        
        // for(int i =1;i<vis.size();i++)
        // {
        //     cout<<vis[i]<<" ";
        // }
        
    }
    int minimumCost(vector<int>& start, vector<int>& end, vector<vector<int>>& specialRoads) {
        vector<int>arr;
        arr.push_back(start[0]);
        arr.push_back(start[1]);
        arr.push_back(end[0]);
        arr.push_back(end[1]);
        arr.push_back(abs(start[0]-end[0])+abs(start[1]-end[1]));
        specialRoads.push_back(arr);
        map<vector<int>,int>mp;
        int cnt=1;
        for(int i=0;i<specialRoads.size();i++)
        {
            vector<int> a={specialRoads[i][0],specialRoads[i][1]};
            vector<int> b={specialRoads[i][2],specialRoads[i][3]};
            if(mp[a]==0)
            {
                mp[a]=cnt;
                cnt++;
            }
            if(mp[b]==0)
            {
                mp[b]=cnt;
                cnt++;
            }
        }
        vector<vector<long>>graph(mp.size()+1,vector<long>(mp.size()+1,LONG_MAX));
        for(int i=0;i<specialRoads.size()-1;i++)
        {
            vector<int> a={specialRoads[i][0],specialRoads[i][1]};
            vector<int> b={specialRoads[i][2],specialRoads[i][3]};
            graph[mp[a]][mp[b]]= graph[mp[a]][mp[b]]>specialRoads[i][4]?specialRoads[i][4]:graph[mp[a]][mp[b]];
            
            for(int j=i+1;j<specialRoads.size()-1;j++)
            {
                vector<int> c={specialRoads[j][0],specialRoads[j][1]};
                vector<int> d={specialRoads[j][2],specialRoads[j][3]};
                graph[mp[d]][mp[a]]=graph[mp[d]][mp[a]]>abs(specialRoads[j][2]-specialRoads[i][0])+abs(specialRoads[j][3]-specialRoads[i][1])?abs(specialRoads[j][2]-specialRoads[i][0])+abs(specialRoads[j][3]-specialRoads[i][1]): graph[mp[d]][mp[a]];
                graph[mp[b]][mp[c]]=graph[mp[b]][mp[c]]>abs(specialRoads[j][0]-specialRoads[i][2])+abs(specialRoads[j][1]-specialRoads[i][3])?abs(specialRoads[j][0]-specialRoads[i][2])+abs(specialRoads[j][1]-specialRoads[i][3]):graph[mp[b]][mp[c]];
            }
            
        }
        graph[mp[start]][mp[end]]=graph[mp[start]][mp[end]]>abs(start[0]-end[0])+abs(start[1]-end[1])?abs(start[0]-end[0])+abs(start[1]-end[1]):graph[mp[start]][mp[end]];
        for(int i=0;i<specialRoads.size()-1;i++)
        {
            vector<int> a={specialRoads[i][0],specialRoads[i][1]};
            vector<int> b={specialRoads[i][2],specialRoads[i][3]};
            graph[mp[start]][mp[a]]=graph[mp[start]][mp[a]]>abs(a[0]-start[0])+abs(a[1]-start[1])?abs(a[0]-start[0])+abs(a[1]-start[1]):graph[mp[start]][mp[a]];
            graph[mp[b]][mp[end]]=graph[mp[b]][mp[end]]>abs(b[0]-end[0])+abs(b[1]-end[1])?abs(b[0]-end[0])+abs(b[1]-end[1]):graph[mp[b]][mp[end]];
        }
        // for(auto it :mp)
        // {
        //     for (auto i:it.first)
        //         cout<<i<<" ";
        //     cout<<it.second<<endl;
        // }
        // for(int i=1;i<graph.size();i++)
        // {
        //     for(int j=1;j<graph.size();j++)
        //     {
        //       cout<<graph[i][j]<<" ";  
        //     }
        //     cout<<endl;
        // }
        vector<long>vis(graph.size(),LONG_MAX);
        bfsShortestPathApproach(graph,vis,mp[start]);
        return vis[mp[end]];
        
        
    }
};