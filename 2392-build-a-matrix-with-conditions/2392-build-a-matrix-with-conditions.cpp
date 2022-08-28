class Solution {
public:
    void topo_sort(vector<int>&ans , vector<int>adj[], vector<bool>& vis,int i)
	{
        
	    vis[i]=1;
	    for(int j=0;j<adj[i].size();j++)
	    {
	        if(vis[adj[i][j]]!=1)
	        {
	            topo_sort(ans,adj,vis,adj[i][j]);
	        }
	    }
	    ans.push_back(i);
	}
    bool check_loop(vector<int>graph[],vector<bool>vis,vector<bool>&pvis, int a)
    {
        // cout<<a<<" ";
        if(vis[a]==1) return false;
        if(pvis[a]==1)
            return true;
        vis[a]=1;
        pvis[a]=1;
        bool ans=true;
        for(int i=0;i<graph[a].size();i++)
        {
            ans=check_loop(graph,vis,pvis,graph[a][i]);
            if(ans==false)
                return false;
        }
        return ans&true;  
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<int>graph1[k+1];
        vector<int>graph2[k+1];
         vector<bool>vis(k+1,0);
         vector<bool>pvis(k+1,0);
        unordered_map<int,unordered_map<int,bool>>mp1,mp2;
        for(int i=0;i<col.size();i++)
        {
            if(mp2[col[i][0]][col[i][1]]==0)
            graph1[col[i][0]].push_back(col[i][1]);
            mp2[col[i][0]][col[i][1]]=1;
            
        }
        for(int i=0;i<row.size();i++)
        {
            if(mp1[row[i][0]][row[i][1]]==0)
            graph2[row[i][0]].push_back(row[i][1]); 
            mp1[row[i][0]][row[i][1]]=1;
        }
        vector<vector<int>>res;
        bool a=true;
        for(int i=1;i<=k;i++)
        {
            vector<bool>vis1(k+1,0);
            if(vis[i]==0)
             a=check_loop(graph1,vis1,vis,i);
            if(a==false)
                return res; 
            
        }
        for(int i=1;i<=k;i++)
        {
            vector<bool>vis2(k+1,0);
            if(pvis[i]==0)
             a=check_loop(graph2,vis2,pvis,i);
            if(a==false)
                return res;   
        }
        vector<bool>vis1(k+1,0);
        vector<bool>vis2(k+1,0);
        vector<int>ans1;
        vector<int>ans2;
        for(int i=1;i<=k;i++)
        {
            if(vis1[i]==0)
            {
                topo_sort(ans1,graph1,vis1,i);
            }
            if(vis2[i]==0)
            {
                topo_sort(ans2,graph2,vis2,i);
            }
        }
        reverse(ans1.begin(),ans1.end());
        reverse(ans2.begin(),ans2.end());
        vector<vector<int>>sol(k,vector<int>(k,0));
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++)
        {
            sol[0][i]=ans1[i]; 
            mp[ans1[i]]=i;
        }
        int j=0;
        for(auto it:ans2)
        {
            int b=mp[it];
            sol[0][b]=0;
            sol[j][b]=it;
            j++;
            
        }
        return sol;
        
        
        
        
        
    
        
        
        
    }
};