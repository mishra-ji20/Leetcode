class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1)
            return "";
        int a,b;
        if(s.size()&1)
        {
           a=(s.size()/2)-1;
           b=(s.size()/2)+1;
        }
        else
        {
            a=(s.size()/2)-1;
            b=(s.size()/2);
        }
        for(int i=0;i<=a;i++)
        {
            if(s[i]!='a')
            {
                s[i]='a';
                return s;
            }
        }
        for(int j=s.size()-1;j>=b/2;j--)
        {
            if(s[j]!='b')
            {
                s[j]='b';
                return s;
            }
        }
        return "";
        
        
        
    }
};