class Solution {
public:
    bool check(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' ||a=='O' || a=='U')
            return true;
        return false;
    }
    string sortVowels(string s) {
        string t;
        map<int,int>mp;
        for(int i=0;i<s.size();i++)
        {

            if(check(s[i])){
                
                mp[s[i]]++;
                
            }
            if(!check(s[i]))
                t.push_back(s[i]);
            else
                t.push_back('a');
        }
        auto it=mp.begin();
        for(int i=0;i<t.size();i++)
        {
            cout<<(it->first)<<' '<<it->second<<endl;
           
            if(check(t[i]))
            {
               t[i]=it->first; 
                it->second=it->second-1;
                 if(it->second==0)
                it++;
            }
        }
        return t;
        
    }
};