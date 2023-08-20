class Solution {
public:
    bool nodeSorting(unordered_map<int,vector<int>>&graph,int &a,unordered_map<int,int>tempVis,unordered_map<int,int>&vis,vector<int>&res){
        if(tempVis[a])
            return false;
        if(vis[a])
            return true;
        tempVis[a]=1;
        vis[a]=1;
        bool flag=true;
        for(int i=0;i<graph[a].size();i++)
        {
            flag=flag & nodeSorting(graph,graph[a][i],tempVis,vis,res);   
        }
        res.push_back(a);
        return flag;
    }
    bool groupSorting(vector<int>groupGraph[],int a,vector<int>tempVis,vector<int>&vis,vector<int>&ans,vector<unordered_map<int,vector<int>>>&nodeGraph){
        // cout<<a<<' ';
        if(tempVis[a])
            return false;
        if(vis[a])
            return true;
        tempVis[a]=1;
        vis[a]=1;
        bool flag=true;
        for(int i=0;i<groupGraph[a].size();i++){
            flag=flag & groupSorting(groupGraph,groupGraph[a][i],tempVis,vis,ans,nodeGraph);
        }
        vector<int>res;
        unordered_map<int,int>nodeTempVis;
        unordered_map<int,int>nodeVis;
        for(auto it : nodeGraph[a]){
            if(nodeVis[it.first]!=1){
                int x=it.first;
                flag=flag & nodeSorting(nodeGraph[a],x,nodeTempVis,nodeVis,res);
            }
        }
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i]);
        }
        // cout<<a<<" ";
        return flag;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<group.size();i++)
        {
            if(group[i]==-1)
            {
                group[i]=m;
                m++;
            }
        }
        vector<unordered_map<int,vector<int>>>nodeGraph(m);
        vector<int>groupGraph[m];
        for(int i=0;i<beforeItems.size();i++)
        {
            for(int j=0;j<beforeItems[i].size();j++)
            {
                if(group[i]!=group[beforeItems[i][j]])
                {
                    groupGraph[group[i]].push_back(group[beforeItems[i][j]]);
                }
                else
                {
                    nodeGraph[group[i]][i].push_back(beforeItems[i][j]);
                }
            }
        }
        for(int i=0;i<group.size();i++)
        {
            nodeGraph[group[i]][i];
        }
        // cout <<endl;
        // cout<<endl;

        vector<int>vis(m,0);
        vector<int>tempVis(m,0);
        vector<int>ans;
        bool flag=true;
        for(int i=0;i<m;i++)
        {
            if(vis[i]!=1)
                flag=flag & groupSorting(groupGraph,i,tempVis,vis,ans,nodeGraph);
        }
        vector<int>tempAns;
        if(flag==false)
            return tempAns;
        else
            return ans;
     
        
    }
};