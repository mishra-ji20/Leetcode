class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>graph[n+1];
        vector<int>hash(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            graph[trust[i][0]].push_back(trust[i][1]);
            hash[trust[i][1]]++;
        }
        for(int i=1;i<hash.size();i++)
        {
            cout<<i<<" ";
            if(hash[i]==n-1 && graph[i].size()==0)
                return i;

        }
        return -1;
        
    }
};