class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        map<string,vector<string>>m;
        for(int i=0;i<str.size();i++)
        {
            string s=str[i];
            sort(str[i].begin(),str[i].end());
           m[str[i]].push_back(s);   
        }
        vector<vector<string>>res;
        for(auto a:m)
        {
            vector<string>temp;
            for(auto b:a.second)
            {
                temp.push_back(b);
            }
            res.push_back(temp);
            
        }
        
        
        return res;
        
    }
};