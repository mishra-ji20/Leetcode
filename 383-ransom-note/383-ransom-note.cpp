class Solution {
public:
    bool canConstruct(string r, string magazine) {
        vector<int>mp(26,0);
        for(int i=0;i<magazine.size();i++)
        {
            mp[magazine[i]-'a']++;
        }
        for(int i=0;i<r.size();i++)
        {
            if(mp[r[i]-'a']>0)
                mp[r[i]-'a']--;
            else
                return 0;
        }
        return 1;
        
    }
};