class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1)
            return s;
      
        string res;
        for(int i=0;i<s.size();)
        {
            string temp="";
            temp=temp+s[i];
            int j=i+1;
            while(s[i]==s[j]){
            temp.push_back(s[j]);
                j++;
            }
            int k=i-1;
            int l=j;
            while(k>=0 && l<s.size())
            {
                if(s[k]==s[l])
                {
                    temp.push_back(s[l]);
                    temp=s[k]+temp;
                }
                else
                    break;
                k--;
                l++;
            }
            if(temp.size()>res.size())
                res=temp;
            i=j;
        }
        return res;
    
    } 
    
};