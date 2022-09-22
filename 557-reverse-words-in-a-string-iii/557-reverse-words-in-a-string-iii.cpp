class Solution {
public:
    void rev(string &s,int i,int j)
    {
        while(i<j)
        {
            swap(s[i],s[j]);
                i++;
            j--;
        }
        
    }
    string reverseWords(string s) {
        for(int i=0;i<s.size();)
        {
            int j=i;
            while(j<s.size() &&s[j]!=' ')
            {
                j++;
            }
            rev(s,i,j-1);
                i=j+1;
            
        }
        return s;
        
        
    }
};