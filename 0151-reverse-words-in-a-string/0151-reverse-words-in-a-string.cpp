class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        
        for(int i=0;i<s.size();)
        {
            string temp="";
            
            while(s[i]!=' ' && i<s.size())
            {
                
                // cout<<s[i];
                temp=temp+s[i];
                i++;
            }
            // cout<<temp<<" ";
            i++;
            if(temp.size()!=0)
            ans.push_back(temp);
        }
        string res="";
        for(int i=ans.size()-1;i>=0;i--)
        {
            for(int j=0;j<ans[i].size();j++)
            {
              res+=ans[i][j];  
            }
            if(i!=0)
            res+=' ';
        }
        return res;
        
    }
};