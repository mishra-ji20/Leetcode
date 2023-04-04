class Solution {
public:
    int partitionString(string s) {
       
        int count=0;
        for(int i=0;i<s.size();)
        {
             unordered_map<char,int>mp;
            while(i<s.size() && mp[s[i]]==0)
            {
                mp[s[i]]=1;
                i++;
                
            }
            count++;
            
        }
        return count;
        
    }
};