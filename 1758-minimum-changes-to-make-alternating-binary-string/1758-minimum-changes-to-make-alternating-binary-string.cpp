class Solution {
public:
    int minOperations(string s) {
        bool flag=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=(flag+'0')){
                cnt1++;
            }
            flag=flag^1;
        }
        flag=1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=(flag+'0')){
                cnt2++;
            }
            flag=flag^1;
        }
        return min(cnt1,cnt2);
        
    }
};