class Solution {
public:
    bool equalFrequency(string s) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        vector<int>ans;
        if(ans.size()==1)
            return true;
        for(auto it:mp)
            ans.push_back(it.second);
        sort(ans.begin(),ans.end());
        ans[0]--;
        int flag=0;
        if(ans[0]==0)
        {
            int j=1;
            for(int i=1;i<ans.size();i++)
            {
                if(ans[i]!=ans[j]){
                    flag++;
                    break;
                }
            }
        }
        else
            flag++;
        ans[0]++;
        ans[ans.size()-1]--;
        int j=0;
        for(int i=1;i<ans.size();i++)
        {
           if(ans[j]!=ans[i]){
               flag++;
               break;
           }
        }
        if(flag!=2)
        return true;
        return false;
            
        
        
        
    }
};