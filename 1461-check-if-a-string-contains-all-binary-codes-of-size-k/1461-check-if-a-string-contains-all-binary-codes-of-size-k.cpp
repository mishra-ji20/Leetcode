class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)
            return false;
        long a=pow(2,k);
        int n=s.size();
        if((n-k+1)<a){
            
            return false;
        }
        vector<bool>res(a,0);
        int num=0;
        int j=0;
        for(int i=n-1;i>=n-k;i--)
        {
            if(s[i]=='1')
                num=num+pow(2,j);
            j++;
           
        }
        // cout<<num<<" ";
        res[num]=1;
        int gc=pow(2,k-1);
        for(int i=n-k-1;i>=0;i--)
        {
            num=num>>1;           
            num=s[i]=='1'?(num|gc):num;
            // cout<<num<<" ";
            res[num]=1;
        }
        for(int i=0;i<res.size();i++)
        {
            if(res[i]==false)
                return false;
        }
        return true;
        
        
        
    }
};