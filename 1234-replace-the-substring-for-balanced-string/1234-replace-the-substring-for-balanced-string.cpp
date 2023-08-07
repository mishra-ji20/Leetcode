class Solution {
public:
    bool check(unordered_map<char,int> &mpValues,unordered_map<char,int> &mpCheck)
    {
        for(auto it: mpValues)
        {
            if(mpCheck[it.first]<it.second)
                return false;
        }
        return true;
        
        
    }
    int balancedString(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int a=s.size()/4;
        for(auto &it:mp)
        {
            it.second=it.second-a>0?it.second-a:0;
        }
        unordered_map<char,int>mpCheck;
        int i=0,j=0;
        
        int ans=INT_MAX;
        while((j<s.size() || check(mp,mpCheck)) && i<s.size())
        {
            // cout<<chec
            while(j<s.size() && (check(mp,mpCheck)==false))
            {
                mpCheck[s[j]]++;
                j++;
                
            }  
            // cout<<j<<' '<<i<<endl;
            ans=min(ans,j-i);
            mpCheck[s[i]]--;
            i++;
            
        }
        return ans;
        
        
    }
};