class Solution {
public:
    int numSplits(string s) {
        vector<int>right(26,0);
        vector<int>left(26,0);
        int disLeft=0;
        int disRight=0;
        int goodCount=0;
        for(int i=0;i<s.size();i++){
            if(right[s[i]-'a']==0){
              disRight++;  
            }
            right[s[i]-'a']++; 
        }
        for(int i=0;i<s.size()-1;i++){
            if(left[s[i]-'a']==0){
                disLeft++;
            }
            left[s[i]-'a']++;
            if(right[s[i]-'a']==1){
                disRight--;
            }
            right[s[i]-'a']--;
            if(disLeft==disRight){
                goodCount++;
            }
        }
        return goodCount;
    }
};