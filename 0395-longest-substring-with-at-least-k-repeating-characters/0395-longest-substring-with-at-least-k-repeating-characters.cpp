class Solution {
public:
    bool check(string str,int k){
        vector<int>freq(26,0);
        for(int i=0;i<str.size();i++){
            freq[str[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0 && freq[i]<k ){
                return false;
            }
        }
        return true;
        
        
    }
    
    int divide(string s,int k){
        if(s.size()<k)
            return 0;
        vector<int>count(26,0);
        vector<int>flag(26,1);
       for(int i=0;i<s.size();i++){
           count[s[i]-'a']++;
           if(count[s[i]-'a']>=k) {
               flag[s[i]-'a']=0;
           }
        }
        int ans=0;
        for(int i=0;i<s.size();)
        {
            // cout<<i<<" ";
            
            int j=i;
            // cout<<flag[s[j]-'a']<<" ";
            if(flag[s[j]-'a']==1){
                j++;
            }else{
                while(j<s.size() && flag[s[j]-'a']==0){
                    // cout<<"aks"<<" ";
                    j++;
                }
                if(check(s.substr(i,j),k)){
                    ans=max(ans,j-i);
                    // cout<<s.substr(i,j)<<endl;
                }else{
                    ans=max(ans,divide(s.substr(i,j),k));
                }
            }
            i=j;
        }
        return ans;
        
    }
    int longestSubstring(string s, int k) {
        int ans=0;
        ans=max(ans,divide(s,k));
        
        return ans;
    }
};