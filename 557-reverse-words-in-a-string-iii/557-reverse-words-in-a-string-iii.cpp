class Solution {
public:
  
    string reverseWords(string s) {
        for(int i=0;i<s.size();)
        {
            int j=i;
            while(j<s.size() &&s[j]!=' ')
            {
                j++;
            }
            int a=i,b=j-1;
            while(a<b)
            {
            swap(s[a],s[b]);
                a++;
                b--;
            }
                i=j+1;
            
        }
        return s;
        
        
    }
};