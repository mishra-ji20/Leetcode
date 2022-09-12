class Solution {
public:
   
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>hash(n,0);
       
        for(int i=0;i<edges.size();i++)
        {
            hash[edges[i][1]]++;
        }
        
        vector<int>res;
        for(int i=0;i<hash.size();i++)
        {
            if(hash[i]==0)
            {
              
                res.push_back(i);
                
            }
        }
        return res;
        
    }
};