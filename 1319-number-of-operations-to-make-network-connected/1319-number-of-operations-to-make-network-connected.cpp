class Solution {
public:
    int func(vector<int>& arr,int i)
    {
        if(i==arr[i])
            return i;
        else
            return func(arr,arr[i]);
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<int>parent;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
        }
        for(int i=0;i<connections.size();i++)
        {
            int a=func(parent,connections[i][0]);
            int b=func(parent,connections[i][1]);
            if(a!=b)
                parent[a]=b;
        }
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<parent.size();i++)
        {
            // cout<<parent[i]<<" ";
            int a=func(parent,i);
            if(mp[a]==0)
            {
                count++;
                mp[a]=1;
            }
        }
        return count-1;
        
    }
};