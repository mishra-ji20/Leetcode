class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        priority_queue<pair<int,char>>q;
        for(auto it:mp)
        {
            q.push({it.second,it.first});
        }
        int n=s.size();
        
        if((n&1) && q.top().first>(n/2)+1)return "";
        if(n%2==0 && q.top().first>(n/2)) return "";
        int flag=0;
        
        for(int i=0;i<s.size();)
        {
            pair<int,char>a=q.top();
            int b=a.first;
            while(b>0)
            {
                if(i<s.size())
                {
                    s[i]=a.second;
                    i=i+2;
                    b--;
                }
                else if(flag==0)
                {
                    i=1;
                    flag=1;
                }
            }
            if(i>=s.size() && flag==0)
            {
                flag=1;
                i=1;
            }
            q.pop();
        }
        return s;
        
    }
};