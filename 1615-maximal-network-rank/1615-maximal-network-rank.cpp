class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_map<int,int>>mp;
        unordered_map<int,int>smp;
        int ma=0;
        int hp=0;
        for(int i=0;i<roads.size();i++)
        {
            mp[roads[i][0]][roads[i][1]]=1;
            mp[roads[i][1]][roads[i][0]]=1;
            smp[roads[i][0]]++;
            smp[roads[i][1]]++;
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i)
                    continue;
                int a=smp[i]+smp[j];
                if(mp[i][j])
                {
                    res=max(res,a-1);
                }
                else
                    res=max(res,a);
                
            }
        }
        return res;
        
        
        
        
    }
};