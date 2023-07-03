class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        vector<char>src(2,0);
        vector<char>target(2,0);
        int flag=0;
        int res=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                if(flag>1)
                    return false;
                
               src[flag]=s[i];
                target[flag]=goal[i];
                flag++;
            }
            else{
            mp[s[i]]++;
            res=max(res,mp[s[i]]);
            }
            
            
        }
       if(flag==0){
           if(res>=2)
           return true;
           else
              return false;
       }
        if(src[0]==target[1] && src[1]==target[0])
            return true;
        return false;
    }
};