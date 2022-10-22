class Solution {
public:
    bool check(unordered_map<char,int>&mp,unordered_map<char,int>&sd){
        for(auto it :mp)
        {
            if(sd[it.first]<it.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int res=INT_MAX;
        unordered_map<char,int>mp;
        unordered_map<char,int>sd;
        int i=0,j=0;
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        int sz=0;
        int a,b,flag=0;
        while(j<s.size())
        {
            while(j<s.size() && check(mp,sd)==false)
            {
                sd[s[j]]++;
                j++;
                sz++;
            }
            while(i<j && check(mp,sd))
            {
                if(res>sz)
                {
                    res=sz;
                    a=i;
                    b=j;
                    flag=1;
                }
                sd[s[i]]--;
                sz--;
                i++;
            }
            
        }
        if(flag)
            return s.substr(a,b-a);
        return "";
    }
};