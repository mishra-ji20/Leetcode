class Solution {
public:
    int numDecodings(string s) {
        vector<int>res(s.size()+1,0);
        if(s[0]=='0')
            return 0;
        res[0]=1;
        res[1]=1;
        for(int i=2;i<res.size();i++)
        {
            int a=s[i-1]-'0';
            int b=s[i-2]-'0';
            if(a==0 && b<=2 && b!=0)
                res[i]=0;
            else if(a==0)
                return 0;
            else 
                res[i]=res[i-1];
            
            if(b!=0  && b*10+a<=26)
                res[i]=res[i]+res[i-2];     
           
        }
        return res[s.size()];
        
    }
};