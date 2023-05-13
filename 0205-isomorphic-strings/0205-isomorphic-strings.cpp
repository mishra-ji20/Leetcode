class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        for(int i=0;i<s.size();i++)
        {
            if((mp1[s[i]-'a'+1]==0 && mp2[t[i]-'a'+1]==0) ||( mp1[s[i]-'a'+1]==t[i]-'a'+1 && mp2[t[i]-'a'+1]==s[i]-'a'+1)){
                mp1[s[i]-'a'+1]=t[i]-'a'+1;
                mp2[t[i]-'a'+1]=s[i]-'a'+1;
            }
            else
                return false;
        }
        return true;
    }
};