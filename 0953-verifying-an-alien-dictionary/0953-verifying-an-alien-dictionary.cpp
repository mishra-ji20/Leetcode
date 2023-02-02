class Solution {
public:
    bool static comp(char a,char b)
    {
        if(a<=b)
            return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char>ans(26);
        for(int i=0;i<26;i++)
        {
            ans[order[i]-'a']=('a'+i);
        }
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                words[i][j]=ans[words[i][j]-'a'];
            }
        }
        
        return is_sorted(words.begin(),words.end());
        
    }
};