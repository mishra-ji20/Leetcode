class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size())
            return ans;
        
        vector<int>mp(26,0);
        vector<int>mp1(26,0);
        for(int i=0;i<p.size();i++)
        {
            mp[p[i]-'a']++;
        }
        int sum=0;
        vector<bool>res(s.size(),0);
        for(int i=0;i<p.size();i++)
        {
            mp1[s[i]-'a']++;
        }
        int i=0;
        int j=p.size()-1;
        while(j<s.size())
        {
            int flag=0;
            for(int i=0;i<26;i++)
            {
                if(mp[i]!=mp1[i])
                {
                    flag=1;
                }
            }
            if(flag==0)
                ans.push_back(i);
            mp1[s[i]-'a']--;
            i++;
            j++;
            if(j<s.size())
                mp1[s[j]-'a']++;
        }
        return ans;
        
        
        
    }
};