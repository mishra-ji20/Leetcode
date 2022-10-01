class Solution {
public:
    int minSwaps(string s) {
        int c1=0;
        int c0=0;
        for(int i=0;i<s.size();i++)
        s[i]=='1'?c1++:c0++;
        if(abs(c1-c0)>1)
            return -1;
        int flag=0;
        if(c1>c0)
            flag=1;
        else if(c0>c1)
            flag=2;
        int ans1=0,ans2=0;
        for(int i=0;i<s.size();i=i+2)
        {
            if(s[i]!='1')
                ans1++;
            
        }
        if(flag==1)
                return ans1;
         for(int i=1;i<s.size();i=i+2)
        {
            if(s[i]!='1')
                ans2++;
            
        }
         if(flag==2)
                return ans2;
        return min(ans1,ans2);
        
        
    }
};