class Solution {
public:
    string comp(string s1,string s2){
        if(s1==""){
            return s2;
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]>s2[i]){
                return s1;
            }else if(s2[i]>s1[i]){
                return s2;
            }
        }
        return s2;
    }
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                ans=comp(ans,num.substr(i,3));
            }
        }
        return ans;
        
    }
};