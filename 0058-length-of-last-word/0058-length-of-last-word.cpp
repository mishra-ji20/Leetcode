class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr=0;
        for(int i=0;i<s.size();){
            
            int k=0;
            while(i<s.size() && s[i]!=' ')
            {
               k++;
               i++;
            }
            i++;
            if(k!=0)
                curr=k;
               
        }
        return curr;
        
        
    }
};