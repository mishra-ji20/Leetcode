class Solution {
public:
    int find(vector<int>& parent,int a)
    {
        if(a==parent[a])
            return a;
        return parent[a]=find(parent,parent[a]);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parent(n+1);
        int size=n;
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        int cnt=n;
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==3)
            {
                int a=find(parent,edges[i][1]);
                int b=find(parent,edges[i][2]);
                if(a!=b)
                    cnt--;
                    
                parent[a]=b;
            }
        }
        vector<int>parentA(n+1);
        int k1=cnt;
        for(int i=1;i<parent.size();i++)
        {
            parentA[i]=parent[i];
        }
       for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==1)
            {
                int a=find(parentA,edges[i][1]);
                int b=find(parentA,edges[i][2]);
                if(a!=b)
                    k1--;
                parentA[a]=b;
            }
        }
        if(k1!=1)
            return -1;
        vector<int>parentB(n+1);
        int k2=cnt;
        for(int i=1;i<parent.size();i++)
        {
            parentB[i]=parent[i];
        }
       for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==2)
            {
                int a=find(parentB,edges[i][1]);
                int b=find(parentB,edges[i][2]);
                if(a!=b)
                    k2--;
                parentB[a]=b;
            }
        }
        if(k2!=1)
            return -1;
        return edges.size()-((n-1)+cnt-1);    
    }
};