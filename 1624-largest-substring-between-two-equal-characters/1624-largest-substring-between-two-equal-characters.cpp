class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>first(26,0);
        vector<int>last(26,0);
        for(int i=0;i<s.size();i++){
            if(first[s[i]-'a']==0){
               first[s[i]-'a']=i+1; 
            }
            last[s[i]-'a']=i+1;
        }
        int ans=0;
        for(int i=0;i<26;i++){
           ans=max(ans,(last[i]-first[i])); 
        }
        return ans-1;
        
    }
};