class Solution {
public:
    int maxScore(string s) {
        int oneCount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                oneCount++;
            }
        }
        int count=s[0]=='1'?-1:1;
        int ma=oneCount+count;
        for(int i=1;i<s.size()-1;i++){
            if(s[i]=='0'){
                count++;
            }else{
                count--;
            }
            ma=max(oneCount+count,ma);
        }
        return ma;
        
    }
};