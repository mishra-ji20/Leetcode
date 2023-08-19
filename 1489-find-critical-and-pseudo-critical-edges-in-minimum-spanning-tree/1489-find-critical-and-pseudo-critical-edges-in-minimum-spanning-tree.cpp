class Solution {
public:
    bool isOneComponent(vector<int>family)
    {
        int x=parent(family,0);
        for(int i=1;i<family.size();i++)
        {
            if(x!=parent(family,i))
                return false;
        }
        return true;
    }
    bool pseudoCriticalCheck(vector<int>family,vector<vector<int>> &cost,int bc,int mstCost,vector<vector<int>>& edges)
    {
        int tCost=bc;
        for(int i=0;i<cost.size();i++)
        {
            if(parent(family,edges[cost[i][1]][0])!=parent(family,edges[cost[i][1]][1])){
                family[parent(family,edges[cost[i][1]][1])]=parent(family,edges[cost[i][1]][0]);
                tCost+=cost[i][0];
            
            }
        }
        // cout<<tCost<<" ";
        if(tCost==mstCost && (isOneComponent(family)))
            return 1;
        return 0;
        
    }
    bool criticalCheck(vector<int>family,vector<vector<int>> &cost,int rejected,int mstCost,vector<vector<int>>& edges)
    {
        int tCost=0;
        for(int i=0;i<cost.size();i++)
        {
            if(cost[i][1]!=rejected)
            if(parent(family,edges[cost[i][1]][0])!=parent(family,edges[cost[i][1]][1])){
                family[parent(family,edges[cost[i][1]][1])]=parent(family,edges[cost[i][1]][0]);
                tCost+=cost[i][0];
            
            }
        }
        if(tCost>mstCost || (!isOneComponent(family)))
            return 1;
        return 0;
        
    }
    int parent(vector<int> & family,int i){
        if(i==family[i])
            return i;
        family[i]=parent(family,family[i]);
        return family[i];
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>>cost;
        vector<int>critical;
        vector<int>pseudoCritical;
        vector<vector<int>>res;
        int mstCost=0;
        for(int i=0;i<edges.size();i++)
        {
            cost.push_back({edges[i][2],i});
        }
        sort(cost.begin(),cost.end());
        vector<int>family(n);
        for(int i=0;i<n;i++)
        {
            family[i]=i;
        }
        for(int i=0;i<cost.size();i++)
        {
            if(parent(family,edges[cost[i][1]][0])!=parent(family,edges[cost[i][1]][1])){
                family[parent(family,edges[cost[i][1]][1])]=parent(family,edges[cost[i][1]][0]);
                mstCost+=cost[i][0];
            }
        }
        for(int i=0;i<cost.size();i++)
        {
                vector<int>tempFamily(n);
                for(int i=0;i<n;i++)
                {
                    tempFamily[i]=i;
                }
                if(criticalCheck(tempFamily,cost,cost[i][1],mstCost,edges))
                    critical.push_back(cost[i][1]);
                else{
                    
                tempFamily[edges[cost[i][1]][0]]=edges[cost[i][1]][1];
                    // cout<<edges[cost[i][1]][0]<<" "<<edges[cost[i][1]][1]<<endl;
                if(pseudoCriticalCheck(tempFamily,cost,cost[i][0],mstCost,edges))
                    pseudoCritical.push_back(cost[i][1]);
                }
        }
        res.push_back(critical);
        res.push_back(pseudoCritical);
        return res;
     
    }
};